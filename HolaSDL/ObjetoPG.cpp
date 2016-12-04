#include "ObjetoPG.h"


ObjetoPG::ObjetoPG()
{
	juegoPG* juego = nullptr;
}

bool ObjetoPG::dentro(int x, int y) const{
	return (pmx >= x && pmx <= (x + ancho) && pmy >= y && pmy <= (y + alto))
	
}

int ObjetoPG::setAlto(int al){

}
ObjetoPG::~ObjetoPG()
{
}
