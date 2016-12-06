#pragma once
#include "SDL.h"
#include "TexturasSDL.h"
#include "GlobosPG.h"
#include "ObjetoJuego.h"
// Practica realizada por Blanca Macazaga Zuazo y Adrián Alcántara Delgado
#include <vector>

int dim = 10; //10; //dimension del array de los globos

const int ancho = 550; //dimensiones de la ventana del juego
const int alto = 600;
const int numText = 3;
enum Texturas_t { TFondo, TGloboN, TGloboM, Tmariposa, Tpremio };

class juegoPG
{
public:
	juegoPG();
	void run();
	void getMousePos(int &mpx, int &mpy)const;
	// los new van a necesitar hacer casting de clase dynamic_cast
	void newBaja(ObjetoJuego* po);
	void newPuntos(int puntuacion);
	void newPremio();
	
	
	SDL_Renderer* getRender()const;
	TexturasSDL* getTextura(Texturas_t et) const { return texturas[et]; } //metodo inline
	
	~juegoPG();

private:
	bool initSDL();
	void closeSDL();
	bool initObjetos();
	void freeObjetos();
	void render() const;
	void onClick();
	void update();
	void handle_event();
	bool initFondo();

	string rutasText [numText];	
	
	int puntos;
	
	bool error, gameOver, exit;
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	bool pausa; //para pausar la actualizacion de los globos
	vector <ObjetoJuego*> objetos; //array de los objetos
	int numG; //numero de globos
	TexturasSDL* texturas[numText];
	int x; //para las posiciones del raton
	int y; //para las posiciones del raton
	
};

