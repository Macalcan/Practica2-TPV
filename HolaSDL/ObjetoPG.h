#pragma once
#include "ObjetoJuego.h"
#include "juegoPG.h"
//#include "GlobosPG.h"
class ObjetoPG : public ObjetoJuego
{
public:

	ObjetoPG();
	virtual ~ObjetoPG();
	bool dentro(int x, int y) const; //llamara a posMouse de juegoPG
	virtual void draw();
	virtual void update();
private:

protected:
	
	
	// sustituye al puntero a la textura y al renderizador de la clase Globo
	juegoPG* juego;
	SDL_Renderer* pRender;

	int x;
	int y;
	int alto;
	int ancho;
	SDL_Rect rectObjeto;
	Texturas_t texturas;
};

