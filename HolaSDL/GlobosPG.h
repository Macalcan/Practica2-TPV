// Practica realizada por Blanca Macazaga Zuazo y Adrián Alcántara Delgado
#pragma once

#include "SDL.h"
#include "ObjetoPG.h"

class GlobosPG: public ObjetoPG
{
public:
	GlobosPG(juegoPG* juego, juegoPG::Texturas_t texturas, int px, int py);
	GlobosPG();
	bool onClick();
	virtual int getPuntos();
	void update();
	virtual ~GlobosPG();

protected:
	
	
	static const int PDES = 30;
	int puntos; //puntos del globo
	bool explotado; //booleana para saber si el globo ha sido explotado
	int inflado; //cuenta el "aire" del globo
	//bool invisible; //booleana de si es visible el globo o no
	
private:
	static const int PVIS = 70;
};

