#include "ObjetoPG.h"


ObjetoPG::ObjetoPG()
{	
	//juego = nullptr;
	
	
}

bool ObjetoPG::dentro(int x, int y) const{
	
	return(y >= rectObjeto.y && y <= rectObjeto.y + rectObjeto.h &&  x >= rectObjeto.x && x <= rectObjeto.x + rectObjeto.w);
	
}
bool ObjetoPG::onClick(){
	int mpx; 
	int mpy;
	juego->getMousePos(mpx, mpy);
	return dentro(mpx, mpy);
}
void ObjetoPG::draw(){
	
}

void ObjetoPG::update() {

}


ObjetoPG::~ObjetoPG()
{
}
