#include "ObjetoPG.h"


ObjetoPG::ObjetoPG()
{	
	juego = nullptr;
	
}

bool ObjetoPG::dentro(int x, int y) const{
	int pmx;
	int pmy;
	juego->getMousePos(pmx, pmy);
	return (pmx >= x && pmx <= (x + ancho) && pmy >= y && pmy <= (y + alto));
	
}

void ObjetoPG::draw(){
	rectObjeto = { x, y, ancho, alto };
	//puntero de tipo juegoPG que apunta a TexturasSDL, de esta clase cogemos el draw y utilizamos renderer y rect
	juego->getTextura(texturas)->draw(juego->getRender, rectObjeto);
}

void ObjetoPG::update() {

}


ObjetoPG::~ObjetoPG()
{
}
