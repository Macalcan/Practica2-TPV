#include "MariposaPG.h"
#include <iostream>
using namespace std;


MariposaPG::MariposaPG(juegoPG* jueg, juegoPG::Texturas_t texturas, int &px, int &py)
{
	texturasa = texturas;
	//rectMarip = rectObjeto;
	posx = px; //posiciones x e y de la mariposa
	posy = py;
	//alto = 100; 
	//ancho = 100;
	juego = jueg;
	game = juego; //puntero a juego
	contClicks = 0; //aun no se le ha dado ningun click
	frameActual = 1; //modificar segun la imagen de la mariposa
	frame = 14;

	RFrame.w = 979 / 14;
	RFrame.h = 72;
	RFrame.x = 0;
	RFrame.y = 0;

	rectObjeto.w = 72;
	rectObjeto.h = 72;
	rectObjeto.x = px;
	rectObjeto.y = py;
	/*rectMarip.w = 72;
	rectMarip.h = 72;
	rectMarip.x = px;
	rectMarip.y = py;*/
}

void MariposaPG::draw() {
	
	game->getTextura(texturasa)->draw(game->getRender(), rectObjeto, RFrame);
}
//--------------------------------------------------------------------------------//
void MariposaPG::update() {

	RFrame.x = (979 / 14)*(frameActual%frame);

	frameActual++;
	if (frameActual < frame - 1)frameActual++;
	else frameActual = 0;

	rectObjeto.x -= 10;
	rectObjeto.y -= 10;

	if (rectObjeto.x <= 0 || rectObjeto.y <= 0) {
		rectObjeto.x = posx;
		rectObjeto.y = posy;
	}

	//RFrame.x = (RFrame.x + RFrame.w) % frame;
	//RFrame.x = (979 / 14)*(frameActual%frame);
}
//--------------------------------------------------------------------------------//
bool MariposaPG::onClick() {
	
	
	if (ObjetoPG::onClick()){
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
