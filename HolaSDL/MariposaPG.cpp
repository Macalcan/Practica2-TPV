#include "MariposaPG.h"



MariposaPG::MariposaPG(juegoPG* juego, Texturas_t texturas, int &px, int &py)
{
	texturas = Tmariposa;
	x = px; //posiciones x e y de la mariposa
	y = py;
	alto = ancho = 100;
	game = juego; //puntero a juego
	contClicks = 0; //aun no se le ha dado ningun click
	frameActual = 1; //modificar segun la imagen de la mariposa
	frame = 14;
}

void MariposaPG::draw() {
	
	//juego->getTextura(Tmariposa)->rectAnimation(frame, frameActual);
	rectObjeto = { ancho / frame * frameActual % frame, 0, ancho / frame, alto };
	ObjetoPG::draw();
}
//--------------------------------------------------------------------------------//
void MariposaPG::update() {

	frameActual++;
	if (onClick()){ //si se hace click en la mariposa se cambia esta de posicion 
		x = rand() % 450;
		y = rand() % 450;
		contClicks++; //sumamos uno a los clicks para que al llegar a tres tengamos un nuevo premio
	}

	if (contClicks == 3){
		contClicks = 0; //contador a 0 para volver a contar los clicks para un nuevo premio
		game->newPremio(); //crea premio
	}
	frameActual++;
	if (frame == 15){
		frameActual = 1;
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
