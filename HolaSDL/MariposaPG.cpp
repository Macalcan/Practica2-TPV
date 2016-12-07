#include "MariposaPG.h"
#include <iostream>
using namespace std;


MariposaPG::MariposaPG(juegoPG* juego, juegoPG::Texturas_t texturas, int &px, int &py)
{
	texturasa = texturas;
	x = px; //posiciones x e y de la mariposa
	y = py;
	alto = 100; 
	ancho = 1000;
	game = juego; //puntero a juego
	contClicks = 0; //aun no se le ha dado ningun click
	frameActual = 1; //modificar segun la imagen de la mariposa
	frame = 14;
}

void MariposaPG::draw() {
	
	rectObjeto = { (ancho / frame) * frameActual % frame, y, ancho / frame, alto };
	game->getTextura(texturasa)->draw(game->getRender(), rectObjeto);
}
//--------------------------------------------------------------------------------//
void MariposaPG::update() {

	frameActual++;

	

	if (frameActual < frame - 1)frameActual++;
	else frameActual = 0;
}
//--------------------------------------------------------------------------------//
bool MariposaPG::onClick() {
	
	int mpx, mpy;
	mpx = mpy = 0;
	juego->getMousePos(mpx, mpy);
	if (dentro(mpx, mpy)) {
		contClicks++; //sumamos uno a los clicks para que al llegar a tres tengamos un nuevo premio
		rectObjeto.x = rand() % 450;
		rectObjeto.y = rand() % 450;
		if (contClicks == 3) {
			game->newPremio(); //crea premio
			contClicks = 0; //contador a 0 para volver a contar los clicks para un nuevo premio
		}
		return true; //si se hace click en mariposa devuelve true sino false
	}
	else return false;
}
//--------------------------------------------------------------------------------//


MariposaPG::~MariposaPG()
{
}
