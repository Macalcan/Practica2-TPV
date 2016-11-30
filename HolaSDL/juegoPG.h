#pragma once
#include "SDL.h"
#include "GlobosPG.h"
#include "ObjetoJuego.h"
// Practica realizada por Blanca Macazaga Zuazo y Adrián Alcántara Delgado
#include <vector>

const int dim = 10; //10; //dimension del array de los globos

const int ancho = 550; //dimensiones de la ventana del juego
const int alto = 600;
class juegoPG
{
public:
	juegoPG();
	void run();
	void getMousePos(int &mpx, int &mpy)const;
	
	SDL_Renderer* getRender()const;
	~juegoPG();

private:
	enum Texturas_t { TFondo, TGloboN, TGloboM, Tmariposa, Tpremio };
	string rutasText [5];
	//TexturasSDL* getTextura(Texturas et)const { return texturas[et] };
	SDL_Renderer* getRender () const;
	void getMousePos(int & mpx, int & mpy) const;
	// los new van a necesitar hacer casting de clase dynamic_cast
	void newBaja(ObjetoJuego* po);
	void newPuntos(ObjetoJuego* po);
	void newPremio(ObjetoJuego* po);
	void initMedia();
	void freeMedia();
	bool explotados[dim]; //array para saber que globos han sido explotados o desinflados
	bool initSDL(); 
	void closeSDL();
	bool initGlobos();
	void freeGlobos();
	void render()const;
	void onClick(int &pmx, int &pmy);
	void update();
	void handle_event();
	int puntos;
	bool initFondo();
	bool error, gameOver, exit;
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	bool pausa; //para pausar la actualizacion de los globos
	ObjetoJuego* globos[dim]; //array de los globos
	TexturasSDL* ptexture [3]; //array de texturas usadas en el juego
	int numG; //numero de globos
};

