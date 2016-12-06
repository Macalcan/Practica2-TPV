#include "PremioPG.h"



PremioPG::PremioPG(juegoPG* juego, int &px, int &py)
{
	x = px;
	y = py;
	alto = ancho = 50;
	puntos = 15;
}

void PremioPG::draw() {
	ObjetoPG::draw();
}
//--------------------------------------------------------------------------------//
void PremioPG::update() {
	if (onClick) {
		juego->newPuntos(puntos);
		juego->newBaja(this);
	}
	else {
		puntos = puntos - 5;
		if (puntos <= 0) juego->newBaja(this);
	}
}
//--------------------------------------------------------------------------------//
bool PremioPG::onClick() {
	return dentro(x, y);
}
//--------------------------------------------------------------------------------//

PremioPG::~PremioPG()
{
}
