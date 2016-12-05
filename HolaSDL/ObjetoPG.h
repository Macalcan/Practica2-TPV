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
	
private:

protected:
	
	void draw();
	void update();
	// sustituye al puntero a la textura y al renderizador de la clase Globo
	juegoPG* juego;
	SDL_Renderer* prender;

	int x;
	int y;
	int alto;
	int ancho;
	SDL_Rect objeto;
	Texturas_t texturas;
};

