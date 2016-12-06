#include "MariposaPG.h"



MariposaPG::MariposaPG(juegoPG* juego, int &px, int &py)
{
	x = px; //posiciones x e y de la mariposa
	y = py;
	alto = ancho = 100;
	
	contClicks = 0; //aun no se le ha dado ningun click
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
	if (onClick){ //si se hace click en la mariposa se cambia esta de posicion 
		x = rand() % 450;
		y = rand() % 450;
		contClicks++; //sumamos uno a los clicks para que al llegar a tres tengamos un nuevo premio
	}

	if (contClicks == 3){
		contClicks = 0; //contador a 0 para volver a contar los clicks para un nuevo premio
		juego->newPremio(); //crea premio
	}
}
//--------------------------------------------------------------------------------//
bool MariposaPG::onClick() {
	return dentro(x, y); //si se hace click en mariposa devuelve true sino false
}
//--------------------------------------------------------------------------------//


MariposaPG::~MariposaPG()
{
}
