// Practica realizada por Blanca Macazaga Zuazo y Adrián Alcántara Delgado
#pragma once
#include "SDL.h"
#include "TexturasSDL.h"
#include "ObjetoPG.h"
class GlobosPG: public ObjetoPG
{
public:
	GlobosPG(juegoPG* juego, int &px, int &py);
	bool onClick();
	void draw() const;
	int getPuntos();
	void update();
	int getAlto();
	int getAncho();
	~GlobosPG();
private:
	juegoPG* game;
	static const int PVIS = 70; 
	static const int PDES = 30;
	TexturasSDL* imagen;
	int puntos; //puntos del globo
	bool explotado; //booleana para saber si el globo ha sido explotado
	int inflado; //cuenta el "aire" del globo
	bool invisible; //booleana de si es visible el globo o no
	
};

