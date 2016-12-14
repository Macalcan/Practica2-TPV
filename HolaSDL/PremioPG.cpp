#include "PremioPG.h"

PremioPG::PremioPG(juegoPG* jueg, juegoPG::Texturas_t texturas, int &px, int &py)
{
	texturasa = texturas;
	juego = jueg;
	game = juego;
	x = px;
	y = py;
	alto = ancho = 50;
	puntosIni = puntos = 15;

	intento = 3;
	rectObjeto.x = x;
	rectObjeto.y = y;
	rectObjeto.w = ancho;
	rectObjeto.h = alto;
}

void PremioPG::draw() {
	rectObjeto = { x, y, ancho, alto };
	if (visible)
		game->getTextura(texturasa)->draw(game->getRender(), rectObjeto);
}
//--------------------------------------------------------------------------------//
void PremioPG::update() {
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

	else if (visible) {
		if (intento > 0)
			intento--;
		else {
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
	x = rand() % 450;
	y = rand() % 450;
	visible = false;
}

PremioPG::~PremioPG()
{
}
