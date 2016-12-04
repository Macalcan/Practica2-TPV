#pragma once
#include "ObjetoJuego.h"
#include "juegoPG.h"
//#include "GlobosPG.h"
class ObjetoPG : public ObjetoJuego
{
public:
	ObjetoPG(juego->Texturas_t);
	virtual ~ObjetoPG();
	bool dentro(int x, int y) const; //llamara a posMouse de juegoPG
	int setAncho(int an) const;
	int setAlto(int al) const;
private:
	juegoPG* juego;
	int alto;
	int ancho;
protected:
	// sustituye al puntero a la textura y al renderizador de la clase Globo
	juegoPG* juego;
};

