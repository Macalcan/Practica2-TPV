#include "MariposaPG.h"



MariposaPG::MariposaPG(juegoPG* juego, int &px, int &py)
{
	x = px;
	y = py;
	contClicks = 0;
	frame = (frame % 6) + 1; //modificar segun la imagen de la mariposa
}

void MariposaPG::draw() {
	//se necesita comprobar que la animacion este bien y si no hay que hacer otro SDL_Rect
	rectObjeto.h = 0;
	rectObjeto.w = 0;
	rectObjeto.x = frame * 128; //actualizacion de los frames de la mariposa
	rectObjeto.y = 0;
	ObjetoPG::draw();
}
//--------------------------------------------------------------------------------//
void MariposaPG::update() {
	if (onClick){
		x = rand() % 450;
		y = rand() % 450;
		contClicks++;
	}

	if (contClicks == 3){
		contClicks = 0;
		//crea premio
	}
}
//--------------------------------------------------------------------------------//
bool MariposaPG::onClick() {
	return dentro(x, y);
}
//--------------------------------------------------------------------------------//


MariposaPG::~MariposaPG()
{
}
