#pragma once

#include "SDL.h"
#include "ObjetoPG.h"

class PremioPG : public ObjetoPG
{
public:
	PremioPG(juegoPG* juego, int &px, int &py);
	void draw();
	void update();
	bool onClick();
	~PremioPG();

private:
	
	int puntos;
};

