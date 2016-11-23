#pragma once
#include "ObjetoJuego.h"
#include "juegoPG.h"
class ObjetoPG : public ObjetoJuego
{
public:
	ObjetoPG();
	virtual ~ObjetoPG();
private:
	juegoPG* juego;
};

