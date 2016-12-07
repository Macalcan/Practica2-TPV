#include "PremioPG.h"



PremioPG::PremioPG(juegoPG* juego, juegoPG::Texturas_t texturas, int &px, int &py)
{
	texturasa = texturas;
	x = px;
	y = py;
	alto = ancho = 50;
	puntos = 15;
}

void PremioPG::draw() {
//	rectObjeto = {x, y, ancho, alto};
	ObjetoPG::draw();
}
//--------------------------------------------------------------------------------//
void PremioPG::update() {
		puntos = puntos + 5;
		if (puntos <= 0) juego->newBaja(this);
	
}
//--------------------------------------------------------------------------------//
bool PremioPG::onClick() {
	int x, y;
	juego->getMousePos(x, y);
	if (dentro(x, y)) {
		juego->newPuntos(this);
		juego->newBaja(this);
	}

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
