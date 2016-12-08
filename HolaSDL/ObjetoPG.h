#pragma once
#include "ObjetoJuego.h"
#include "juegoPG.h"

class ObjetoPG : public ObjetoJuego
{
public:

	ObjetoPG();
	virtual ~ObjetoPG();
	bool dentro(int x, int y) const; //llamara a posMouse de juegoPG
	virtual void draw();
	virtual void update();
	virtual bool onClick();

protected:
	
	// sustituye al puntero a la textura y al renderizador de la clase Globo
	juegoPG* juego;
	SDL_Renderer* pRender;

	int x;
	int y;
	int alto;
	int ancho;
	SDL_Rect rectObjeto;
	juegoPG::Texturas_t texturasa;
};

