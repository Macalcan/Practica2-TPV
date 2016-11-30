// Practica realizada por Blanca Macazaga Zuazo y Adri�n Alc�ntara Delgado
#pragma once
#include "SDL.h"
#include "TexturasSDL.h"
#include "ObjetoPG.h"
class GlobosPG: public ObjetoPG
{
public:
	GlobosPG(ObjetoJuego* juego, TexturasSDL* img, int &px, int &py);
	bool onClick();
	void draw() const;
	int getPuntos();
	void update();
	int getAlto();
	int getAncho();
	~GlobosPG();
private:
	ObjetoJuego* game;
	static const int PVIS = 70; 
	static const int PDES = 30;
	TexturasSDL* imagen;
	int puntos; //puntos del globo
	bool explotado; //booleana para saber si el globo ha sido explotado
	int alto; //alto del globo
	int ancho; //ancho del globo
	int x; //posicion x del globo
	int y; //posicion y del globo
	int inflado; //cuenta el "aire" del globo
	bool invisible; //booleana de si es visible el globo o no
	SDL_Rect balloon; //rect del globo
};

