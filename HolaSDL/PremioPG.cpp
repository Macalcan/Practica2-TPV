#ifndef _H_PremioPG_H
#define _H_PremioPG_H
#include "PremioPG.h"

PremioPG::PremioPG(juegoPG* jueg, juegoPG::Texturas_t texturas, int px, int py) : ObjetoPG(jueg, texturas, px, py)
{
	
	rectObjeto.w = rectObjeto.h = 50;
	puntosIni = puntos = 15;
	intento = 3;

}


//--------------------------------------------------------------------------------//
void PremioPG::update() {
	if (puntos > 0)
		puntos -= 5;
}
//--------------------------------------------------------------------------------//
bool PremioPG::onClick() {
	
	if (ObjetoPG::onClick()) {
		juego->newPuntos(this);
		juego->newBaja(this);
		reiniciaPremio();
		visible = false;
		return true;
	}

	else if (intento > 0) {
		
		intento--;
		if(intento == 0){
			juego->newBaja(this);
			reiniciaPremio();
		}
		return false;
	}

	else return false;
}
//--------------------------------------------------------------------------------//
//getter de puntos del globo
int PremioPG::getPuntos() {
	return puntos;
}
void PremioPG::reiniciaPremio() {
	puntos = puntosIni;
	intento = 3;
	rectObjeto.x = rand() % 450;
	rectObjeto.y = rand() % 450;
	visible = false;
}

PremioPG::~PremioPG()
{
}
#endif