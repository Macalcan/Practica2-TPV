// Practica realizada por Blanca Macazaga Zuazo y Adrián Alcántara Delgado
#include "GlobosPG.h"
using namespace std;


GlobosPG::GlobosPG(ObjetoJuego* juego, TexturasSDL* img, int &px, int &py)
{
	x = px; //posicion en el eje x e y del globo
	y = py;
	imagen = img; //apuntara a la textura del globo ademas de hacer que se dibuje
	game = juego;
	alto = ancho = 100; //tamaño del globo
	explotado = false; 
	invisible = false;
	puntos = 5; //puntos iniciales

	inflado = 100; //inicialmente el globo está totalmente inflado
}


//--------------------------------------------------------------------------------//
void GlobosPG::draw()const{
	if (!invisible){
		SDL_Rect datBalloon;
		datBalloon = { x, y, ancho, alto };
		game->draw();
	}
	/*if (!invisible){ //en caso de estar visible se dibuja
		SDL_Rect datBalloon;
		datBalloon = { x, y, ancho, alto };
		imagen->draw(pRenderer, datBalloon);
	}*/
}
//--------------------------------------------------------------------------------//
bool GlobosPG::onClick(){
	//comprueba si se ha explotado el globo en el rectangulo de la imagen
	
	if (dentro(x, y)){
		invisible = true;
		return explotado = true;
	}
	else return false;
}
//--------------------------------------------------------------------------------//
//actualiza el globo
void GlobosPG::update(){
	//si se ha deshinchado o se ha explotado el globo ya no sera visible 
	if (inflado == 0 || explotado)
		invisible = true;
	else {
		if (rand() % 100 < PVIS) //probabilidad de que sea visible o no
			invisible = false;
		else
			invisible = true;

		if (rand() % 100 < PDES){ //probabilidad de que se desinfle
			inflado -= 10; //disminuye el "aire" que tiene el globo
			alto -= 10; //disminuye el tamaño del globo
			ancho -= 10;
			puntos += 2;//aumentan los puntos que se recibe al explotar el globo cuanto menos inflado este
		}
		//return false;
	}
}
//getter de puntos del globo
int GlobosPG::getPuntos(){
	return puntos;
}

//--------------------------------------------------------------------------------//
GlobosPG::~GlobosPG()
{

}
