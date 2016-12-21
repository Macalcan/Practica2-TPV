#pragma once

#include "SDL.h"
#include "GlobosPG.h"

class GloboA : public GlobosPG
{
public:
	GloboA(juegoPG* jueg, juegoPG::Texturas_t texturas, int &px, int &py);
	
	void update();
	~GloboA();

private:


};


