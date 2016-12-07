#include "PremioPG.h"



PremioPG::PremioPG(juegoPG* juego, Texturas_t texturas, int &px, int &py)
{
	texturas = Tpremio;
	x = px;
	y = py;
	alto = ancho = 50;
	puntos = 15;
}

void PremioPG::draw() {
	rectObjeto = {x, y, ancho, alto};
	ObjetoPG::draw();
}
//--------------------------------------------------------------------------------//
void PremioPG::update() {
	if (onClick()) {
		juego->newPuntos(this);
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
//getter de puntos del globo
int PremioPG::getPuntos() {
	return puntos;
}

PremioPG::~PremioPG()
{
}
