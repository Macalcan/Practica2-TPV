#pragma once

#include "SDL.h"
#include "ObjetoPG.h"

class MariposaPG
{
public:
	MariposaPG(juegoPG* juego, int &px, int &py);
	void draw();
	void update();
	bool onClick();
	~MariposaPG();

private: 
	int x;
	int y;
};

