#pragma once

#include "SDL.h"
#include "ObjetoPG.h"

class MariposaPG : public ObjetoPG
{
public:
	MariposaPG(juegoPG* juego, juegoPG::Texturas_t texturas, int px, int py);
	void draw();
	void update();
	bool onClick();
	~MariposaPG();

private: 
	int contClicks;
	int frame;
	int frameActual;
	SDL_Rect RFrame;
	SDL_Rect rectMarip;
	
	int posx, posy;
};

