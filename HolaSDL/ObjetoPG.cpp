#include "ObjetoPG.h"


ObjetoPG::ObjetoPG()
{	
	//juego = nullptr;
	
	
}

bool ObjetoPG::dentro(int x, int y) const{
	
	return(y >= rectObjeto.y && y <= rectObjeto.y + rectObjeto.h &&  x >= rectObjeto.x && x <= rectObjeto.x + rectObjeto.w);
	
}

void ObjetoPG::draw(){
	//puntero de tipo juegoPG que apunta a TexturasSDL, de esta clase cogemos el draw y utilizamos renderer y rect
	juego->getTextura(texturasa)->draw(juego->getRender(), rectObjeto);
}

void ObjetoPG::update() {

}


ObjetoPG::~ObjetoPG()
{
}
