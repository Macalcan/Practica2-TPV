// Practica realizada por Blanca Macazaga Zuazo y Adrián Alcántara Delgado
#include "juegoPG.h"
#include "TexturasSDL.h"
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "PremioPG.h"
#include "MariposaPG.h"
#include "GlobosPG.h"
#include "GloboA.h"
#include "ObjetoPG.h"
using namespace std;

juegoPG::juegoPG()
{
	srand(SDL_GetTicks());

	SDL_Window * pWindow = nullptr;
	SDL_Renderer * pRenderer = nullptr;

	error = false; //si hay un error se pondrá a true
	exit = false; //si se sale del juego se pondrá a true
	gameOver = false; //si se acaba el juego se pondrá a true
	pausa = false; //se se pulsa p es true y se para la actualizacion de los globos
	puntos = 0; //puntos al comenzar el juego
	initSDL();

	//metemos las rutas de texturas
	rutasText.emplace_back("..\\bmps\\sky.jpg");
	rutasText.emplace_back("..\\bmps\\globoN.png");
	rutasText.emplace_back("..\\bmps\\globoM.png");
	rutasText.emplace_back("..\\bmps\\butterfly.png");
	rutasText.emplace_back("..\\bmps\\Gift.png");
	
	initObjetos();
}
//--------------------------------------------------------------------------------//
bool juegoPG::initSDL() {

	bool carga = true; //si carga es false no se puede cargar la ventana inicializando SDL

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "¡SDL no se ha podido iniciar! \nSDL_Error: " << SDL_GetError() << '\n';
		carga = false;
	}
	else {
		pWindow = SDL_CreateWindow("SDL Balloon", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ancho, alto, SDL_WINDOW_SHOWN);
		if (pWindow == nullptr){
			cout << "¡La ventana no se ha podido crear! \nSDL_Error: " << SDL_GetError() << '\n';
			carga = false;
		}
		else {
			//Toma la superficie de la ventana:
			pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
			SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255); //De momento la ventana sera negra pero despues tendra un fondo
			if (pRenderer == nullptr){
				cout << "¡No se ha podido crear el renderer! \nSDL_Error: " << SDL_GetError() << '\n';
				carga = false;
			}
		}
	}

	return carga;
}
//--------------------------------------------------------------------------------//

SDL_Renderer* juegoPG::getRender() const {
	return pRenderer;
}
//--------------------------------------------------------------------------------//
bool juegoPG::initObjetos() {
	//declaras variables aleatorias x e y que indican la posicion de cada globo
	int x;
	int y;

	//inicializa las texturas de los globos
	for (int i = 0; i < 5; i++) {
		texturas.emplace_back(new TexturasSDL());
		texturas[i]->load(pRenderer, rutasText[i]);
	}
	

	for (int i = 0; i < dim; i++){//creamos un globo en cada vuelta en una posicion aleatoria en el rectangulo de la ventana
		x = rand() % 450;
		y = rand() % 450;
		if (i%2 == 0)
			objetos.emplace_back( new GlobosPG(this, TGloboN, x, y)); //cada globo tendrá la textura 0 o la textura 1
		else
			objetos.emplace_back(new GloboA(this, TGloboM, x, y));
	}
	numPremios = numMariposas = 2;
	for (int i = dim; i < numMariposas + dim; i++){
		x = rand() % 450;
		y = rand() % 450;
		objetos.emplace_back(new MariposaPG(this, Tmariposa, x, y));
	}
	numG = dim; //numero total de globos al principio del juego
	
	for (int i = dim + numMariposas; i < numPremios + numMariposas + dim; i++){
		objetos.emplace_back(new PremioPG(this, Tpremio, x, y));
	}
	
	return (texturas[TGloboN] != nullptr || texturas[Tmariposa] != nullptr || texturas[Tpremio] != nullptr);
}

//--------------------------------------------------------------------------------//
void juegoPG::closeSDL() {
	SDL_DestroyRenderer(pRenderer);
	pRenderer = nullptr;

	SDL_DestroyWindow(pWindow);
	pWindow = nullptr;

	SDL_Quit();
}
//--------------------------------------------------------------------------------//
void juegoPG::freeObjetos() {
	for (int i = 0; i < objetos.size(); i++) {
		delete objetos[i];
		objetos[i] = nullptr;
	}
	//delete de las rutas de codigo
	delete (texturas[TGloboN]);
	texturas[TGloboN] = nullptr;
	delete(texturas[TGloboM]);
	texturas[TGloboM] = nullptr;
	delete (texturas[TFondo]);
	texturas[TFondo] = nullptr;
	delete (texturas[Tmariposa]);
	texturas[Tmariposa] = nullptr;
	delete (texturas[Tpremio]);
	texturas[Tpremio] = nullptr;
	//destruye las texturas de los globos
}
//--------------------------------------------------------------------------------//
//dibuja los globos que estan visibles, para ello deberia hacer probablemente un for recorriendo todos los globos y accediendo a su atributo visible,
//en caso de que el globo lo sea se dibuja con draw(pRenderer), pRenderer está declarado arriba pero no asginado
void juegoPG::render() const {

	SDL_RenderClear(pRenderer); //"limpia" el render donde vamos a dibujar el siguiente frame
	
	SDL_Rect rect; //rect para el fondo
	rect = {0, 0, ancho, alto};
	texturas[TFondo]->draw(pRenderer, rect); //dibuja el fondo

	for (int i = 0; i < objetos.size(); i++){ //dibuja los globos
		objetos[i]->draw();
	}

	//Show the window
	SDL_RenderPresent(pRenderer);
}
//--------------------------------------------------------------------------------//
//comprueba si al hacer click ha explotado el globo a traves del metodo onClick de GlobosPG y si lo ha explotado saca los puntos del globo y los suma
//a los puntos conseguidos en total
void juegoPG::onClick(){
	bool click = false;
	//cout << objetos.size();
	//int size = 11;
	for (int i = objetos.size() - 1; i >= 0 && (!click); i--){
		if (objetos[i]->onClick()){
			click = true;
		}
	}
}
//--------------------------------------------------------------------------------//
//recorre todos los globos actualizandolos y comprobando si se han desinflado o explotado, y por lo tanto no son visibles
void juegoPG::update() {
	for (int i = 0; i < objetos.size(); i++) {
		objetos[i]->update(); //si se ha exlpotado el globo se determina en nuestro array de booleanos y desciende el numero de globos
	}
}
//--------------------------------------------------------------------------------//
void juegoPG::handle_event() {
	SDL_Event e;
	if (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) exit = true;
		else if (e.type == SDL_MOUSEBUTTONUP) {
			if (e.button.button == SDL_BUTTON_LEFT) {
				cout << "CLICK";
				mx = e.button.x;
				my = e.button.y;
				onClick();
			}
		}
		else if (e.type == SDL_KEYUP){ //si se pulsa una tecla comprueba que es p
			if (e.key.keysym.sym == SDLK_p){
				if (!pausa) //si pausa es false se activa y sino se desactiva
					pausa = true;
				else
					pausa = false;
			}
		}
	}
}
//--------------------------------------------------------------------------------//
void juegoPG::run()
{
	if (!error){
		Uint32 MSxUpdate = 500;
		cout << "Play \n";
		Uint32 lastUpdate = SDL_GetTicks();
		string puntuacion = "preparado!!?? ";
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Practica1", puntuacion.c_str(), nullptr);
		
		render();
		handle_event();
		while (!exit && !gameOver){
			if (SDL_GetTicks() - lastUpdate >= MSxUpdate){//while(elapsed >= MSxUpdate)
				if (!pausa)
					update();
				
				lastUpdate = SDL_GetTicks();
			}

			render();
			handle_event();
			if (numG == 0) { // Cuando el juego acaba aparece una ventana con la puntuacion que hemos conseguido y con un boton OK que cuando se pulsa se cierran las consolas
				string puntuacion = "Puntuacion: ";
				puntuacion += to_string(puntos);
				SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Has terminado!!", puntuacion.c_str(), nullptr);
				gameOver = true;
			}
		}

		render();
		if (exit) cout << "Exit \n";
		else cout << "Has obtenido " << puntos << " puntos \n";
		SDL_Delay(1000);
	}



}
//--------------------------------------------------------------------------------//
void juegoPG::getMousePos(int &mpx, int &mpy) const {
	//hay que añadir atributos para la posicion del raton (debe actualizarse en onClick)
	mpx = mx;
	mpy = my;
}
//--------------------------------------------------------------------------------//
void juegoPG::newBaja(ObjetoJuego* po) {
	//queremos saber si lo que destruimos es un globo
	if (dynamic_cast<GlobosPG*>(po)) {
		numG--;
	}
	else if (typeid(*po) == typeid(PremioPG)) {
		dynamic_cast<PremioPG*>(po)->visible = false;
	}
}
//--------------------------------------------------------------------------------//
void juegoPG::newPuntos(ObjetoJuego* po) {
	if (dynamic_cast<GlobosPG*>(po))
		puntos += dynamic_cast<GlobosPG*>(po)->getPuntos();
	else if (typeid(*po) == typeid(PremioPG))
		puntos += dynamic_cast<PremioPG*>(po)->getPuntos();
}
//--------------------------------------------------------------------------------//
void juegoPG::newPremio() {
	bool premioNuevo = false;
	for (int i = objetos.size() - 1; i > objetos.size() - numPremios -1 && !(premioNuevo); i--){
		if (!(dynamic_cast<PremioPG*>(objetos[i])->visible))
		{
			dynamic_cast<PremioPG*>(objetos[i])->visible = true;
			premioNuevo = true;
		}
	}

}
//--------------------------------------------------------------------------------//

juegoPG::~juegoPG()
{
	closeSDL();
	freeObjetos();
	pWindow = nullptr;
	pRenderer = nullptr;
}
