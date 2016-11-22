#pragma once
#include "SDL.h"
#include "GlobosPG.h"
// Practica realizada por Blanca Macazaga Zuazo y Adrián Alcántara Delgado
#include <vector>

const int dim = 2; //10; //dimension del array de los globos

const int ancho = 550; //dimensiones de la ventana del juego
const int alto = 600;
class juegoPG
{
public:
	juegoPG();
	void run();
	~juegoPG();
private:
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
	GlobosPG* globos[dim]; //array de los globos
	TexturasSDL* ptexture [3]; //array de texturas usadas en el juego
	int numG; //numero de globos
};

