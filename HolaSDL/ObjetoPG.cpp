#include "ObjetoPG.h"


ObjetoPG::ObjetoPG()
{	
	juego = nullptr;
	prender = juego->getRender();
}

bool ObjetoPG::dentro(int x, int y) const{
	int pmx;
	int pmy;
	juego->getMousePos(pmx, pmy);
	return (pmx >= x && pmx <= (x + ancho) && pmy >= y && pmy <= (y + alto));
	
}

void ObjetoPG::draw(){
	objeto = { x, y, ancho, alto };
	
}

void ObjetoPG::update() {

}

ObjetoPG::~ObjetoPG()
{
}
