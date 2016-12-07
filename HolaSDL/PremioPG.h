#pragma once

#include "SDL.h"
#include "ObjetoPG.h"

class PremioPG : public ObjetoPG
{
public:
	PremioPG(juegoPG* juego, juegoPG::Texturas_t texturas, int &px, int &py);
	void draw();
	void update();
	bool onClick();
	int getPuntos();
	~PremioPG();

private:
	juegoPG* game;
	int puntos;
};

