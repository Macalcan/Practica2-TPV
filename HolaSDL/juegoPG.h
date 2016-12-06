#pragma once
#include "SDL.h"
#include "TexturasSDL.h"
#include "GlobosPG.h"
#include "ObjetoJuego.h"
// Practica realizada por Blanca Macazaga Zuazo y Adrián Alcántara Delgado
#include <vector>

const int dim = 10; //10; //dimension del array de los globos

const int ancho = 550; //dimensiones de la ventana del juego
const int alto = 600;
const int numText = 3;
enum Texturas_t { TFondo, TGloboN, TGloboM }; //, Tmariposa, Tpremio

class juegoPG
{
public:
	juegoPG();
	void run();
	void getMousePos(int &mpx, int &mpy)const;
	void getMousePos(int & mpx, int & mpy) const;
	// los new van a necesitar hacer casting de clase dynamic_cast
	void newBaja(ObjetoJuego* po);
	void newPuntos(ObjetoJuego* po);
	void newPremio();
	
	bool explotados[dim]; //array para saber que globos han sido explotados o desinflados
	bool initSDL();
	void closeSDL();
	bool initGlobos();
	void freeGlobos();
	void render()const;
	void onClick();
	void update();
	void handle_event();
	bool initFondo();
	SDL_Renderer* getRender()const;
	TexturasSDL* getTextura(Texturas_t et) const { return texturas[et]; } //metodo inline
	
	~juegoPG();

private:
	
//};
	string rutasText [numText];	
	
	int puntos;
	
	bool error, gameOver, exit;
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	bool pausa; //para pausar la actualizacion de los globos
	ObjetoJuego* objetos[dim]; //array de los objetos
	int numG; //numero de globos
	TexturasSDL* texturas[numText];
	int x; //para las posiciones del raton
	int y; //para las posiciones del raton
	
};

