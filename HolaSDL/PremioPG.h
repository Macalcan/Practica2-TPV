#pragma once

#include "SDL.h"
#include "ObjetoPG.h"

class PremioPG : public ObjetoPG
{
public:
	PremioPG(juegoPG* juego, juegoPG::Texturas_t texturas, int px, int py);
	void draw();
	void update();
	bool onClick();
	int getPuntos();
	void reiniciaPremio();
	~PremioPG();

private:
	juegoPG* game;
	int puntos, intento, puntosIni;
	int premiox, premioy;
	SDL_Rect rectPremio;
	bool visible;
};

