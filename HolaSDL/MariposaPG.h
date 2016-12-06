#pragma once

#include "SDL.h"
#include "ObjetoPG.h"

class MariposaPG : public ObjetoPG
{
public:
	MariposaPG(juegoPG* juego, int &px, int &py);
	void draw();
	void update();
	bool onClick();
	~MariposaPG();

private: 
	int contClicks;
	int x;
	int y;
	int frame;
	juegoPG* game;
};

