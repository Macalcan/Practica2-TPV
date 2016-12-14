//Ampliacion realizada por Adrian Alcantara Delgado
#include "GloboA.h"
using namespace std;

GloboA::GloboA(juegoPG* jueg, juegoPG::Texturas_t texturas, int &px, int &py) : GlobosPG(jueg, texturas, px, py)
{
	texturasa = texturas;
	x = px; //posicion en el eje x e y del globo
	y = py;
	juego = jueg;
	game = juego; //puntero a la clase juegoPG
	alto = ancho = 100; //tamaño del globo
	explotado = false;
	invisible = false;
	puntos = 5; //puntos iniciales

	inflado = 100; //inicialmente el globo está totalmente inflado
}
//--------------------------------------------------------------------------------//
void GloboA::draw() {
	rectObjeto = { x, y, ancho, alto };
	if (!invisible){
		//ObjetoPG::draw();
		game->getTextura(texturasa)->draw(game->getRender(), rectObjeto);
	}
}
//--------------------------------------------------------------------------------//
bool GloboA::onClick(){
	//comprueba si se ha explotado el globo en el rectangulo de la imagen

	if (ObjetoPG::onClick() && !explotado){
		invisible = true;
		explotado = true;
		juego->newBaja(this);
		juego->newPuntos(this);
		return true;
	}
	else return false;

}
//--------------------------------------------------------------------------------//
//actualiza el globo
void GloboA::update(){
	//si se ha deshinchado o se ha explotado el globo ya no sera visible 
	if (!explotado){
		if (inflado <= 0){
			explotado = true;
			invisible = true;
			juego->newBaja(this);
		}
		else {
			if (rand() % 100 < PDES){ //probabilidad de que se desinfle
				inflado -= 10; //disminuye el "aire" que tiene el globo
				alto -= 10; //disminuye el tamaño del globo
				ancho -= 10;
				if (y - 10 >= 0){
					y -= 10;
					//aumentan los puntos que se recibe al explotar el globo cuanto menos inflado este
					puntos += 2;
				}
				else {
					y = 0;
					puntos += 2;
					if (puntos/ 2 > 1)
						puntos = puntos / 2;
					else puntos = 0;
				}
			}

		}
	}
}
//--------------------------------------------------------------------------------//
//getter de puntos del globo
int GloboA::getPuntos(){
	return puntos;
}
//--------------------------------------------------------------------------------//
GloboA::~GloboA()
{
}
