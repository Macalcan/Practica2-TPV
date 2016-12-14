//Ampliacion realizada por Adrian Alcantara Delgado
#pragma once
#include "SDL.h"
#include "GlobosPG.h"
class GloboA: public GlobosPG
{
public:
	GloboA(juegoPG* juego, juegoPG::Texturas_t texturas, int &px, int &py);

	bool onClick();
	void draw();
	int getPuntos();
	void update();

	~GloboA();

private:
	juegoPG* game;
	static const int PDES = 30;
	int puntos; //puntos del globo
	bool explotado; //booleana para saber si el globo ha sido explotado
	int inflado; //cuenta el "aire" del globo
	bool invisible; //booleana de si es visible el globo o no
	
};

