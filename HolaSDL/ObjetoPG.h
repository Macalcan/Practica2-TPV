#pragma once
#include "ObjetoJuego.h"
#include "juegoPG.h"

class ObjetoPG : public ObjetoJuego
{
public:

	ObjetoPG();
	virtual ~ObjetoPG();
	virtual void draw();
	virtual void update();
	virtual bool onClick();

protected:

	ObjetoPG(juegoPG* juego, juegoPG::Texturas_t texturas, int px, int py);
	bool dentro(int x, int y) const; //llamara a posMouse de juegoPG
	// sustituye al puntero a la textura y al renderizador de la clase Globo
	juegoPG* game;
	SDL_Renderer* pRender;

	int x;
	int y;
	int alto;
	int ancho;
	SDL_Rect rectObjeto;
	juegoPG::Texturas_t texturasa;
};

