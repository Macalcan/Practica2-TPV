// Practica realizada por Blanca Macazaga Zuazo y Adrián Alcántara Delgado
#pragma once
#include "SDL.h"
#include "TexturasSDL.h"

class GlobosPG
{
public:
	GlobosPG(TexturasSDL* img, int &px, int &py);
	bool onClick(int &pmx, int &pmy);
	void draw(SDL_Renderer* pRenderer) const;
	int getPuntos();
	bool update();
	
	~GlobosPG();
private:
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

