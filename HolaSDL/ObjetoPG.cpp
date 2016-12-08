#include "ObjetoPG.h"


ObjetoPG::ObjetoPG()
{
}
ObjetoPG::ObjetoPG(juegoPG* juego, juegoPG::Texturas_t texturas, int px, int py):game(juego)
{	
	//game = juego;
	rectObjeto.x = px;
	rectObjeto.y = py;
}

bool ObjetoPG::dentro(int x, int y) const{
	
	return((y >= rectObjeto.y) && (y <= (rectObjeto.y + rectObjeto.h)) &&  (x >= rectObjeto.x) && (x <= (rectObjeto.x + rectObjeto.w)));
}

void ObjetoPG::draw(){
	
}

void ObjetoPG::update() {

}
bool ObjetoPG::onClick() {
	int mx, my;
	game->getMousePos(mx, my);
	return dentro(mx, my);
}


ObjetoPG::~ObjetoPG()
{
}
