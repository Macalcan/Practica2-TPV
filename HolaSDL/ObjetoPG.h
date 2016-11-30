#pragma once
#include "ObjetoJuego.h"
#include "juegoPG.h"
//#include "GlobosPG.h"
class ObjetoPG : public ObjetoJuego
{
public:
	ObjetoPG();
	virtual ~ObjetoPG();
	bool dentro(int x, int y) const; //llamara a posMouse de juegoPG
	int setAncho(int an);
	int setAlto(int al);
private:
	juegoPG* juego;
	int alto;
	int ancho;
	
	
};

