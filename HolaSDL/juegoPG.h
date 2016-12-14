#pragma once
#include "SDL.h"
#include "TexturasSDL.h"
#include "ObjetoJuego.h"
// Practica realizada por Blanca Macazaga Zuazo y Adrián Alcántara Delgado
#include <vector>


const int ancho = 550; //dimensiones de la ventana del juego
const int alto = 600;
const int numText = 4;


class juegoPG
{
public:
	juegoPG();
	void run();
	void getMousePos(int &mpx, int &mpy)const;
	// los new van a necesitar hacer casting de clase dynamic_cast
	void newBaja(ObjetoJuego* po);
	void newPuntos(ObjetoJuego * po);
	void newPremio();
	
	enum Texturas_t { TFondo, TGloboN, TGloboM, Tmariposa, Tpremio };
	SDL_Renderer* getRender()const;
	TexturasSDL* getTextura(Texturas_t et) const { return texturas[et]; } //metodo inline
	
	~juegoPG();

private:
	int dim = 10; //10; //dimension del array de los globos

	bool initSDL();
	void closeSDL();
	bool initObjetos();
	void freeObjetos();
	void render() const;
	void onClick();
	void update();
	void handle_event();

	std::vector<std::string> rutasText;	
	
	int puntos;
	int numMariposas;
	int numPremios;
	bool error, gameOver, exit;
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	bool pausa; //para pausar la actualizacion de los globos
	vector <ObjetoJuego*> objetos; //array de los objetos
	int numG; //numero de globos
	std::vector<TexturasSDL*> texturas;
	int x; //para las posiciones del raton
	int y; //para las posiciones del raton
	int mx, my;
	
};

