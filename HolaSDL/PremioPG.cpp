#include "PremioPG.h"



PremioPG::PremioPG(juegoPG* juego, juegoPG::Texturas_t texturas, int px, int py)
{
	texturasa = texturas;
	rectPremio = rectObjeto;
	game = juego;
	premiox = px;
	premioy = py;
	alto = ancho = 50;
	puntos = puntosIni = 15;
	visible = false;
	intento = 3;

	rectPremio.x = premiox;
	rectPremio.y = premioy;
	rectPremio.w = ancho;
	rectPremio.h = alto;

}

void PremioPG::draw() {
	if (visible)
		game->getTextura(texturasa)->draw(game->getRender(), rectObjeto);
}
//--------------------------------------------------------------------------------//
void PremioPG::update() {
	puntos -= 5;
}
//--------------------------------------------------------------------------------//
void PremioPG::reiniciaPremio() {
	puntos = puntosIni;
	intento = 3;
	rectPremio.x = rand() % 450;
	rectPremio.y = rand() % 450;
	visible = false;
}
//--------------------------------------------------------------------------------//
bool PremioPG::onClick() {
	
	if (ObjetoPG::onClick()) {
		game->newPuntos(this);
		game->newBaja(this);
		reiniciaPremio();
		return true;
	}

	else if (visible) {
		if (intento > 0)
			intento--;
		else {
			game->newBaja(this);
			reiniciaPremio();
			return false;
		}
		return false;
	}
}
//--------------------------------------------------------------------------------//
//getter de puntos del globo
int PremioPG::getPuntos() {
	return puntos;
}

PremioPG::~PremioPG()
{
}
