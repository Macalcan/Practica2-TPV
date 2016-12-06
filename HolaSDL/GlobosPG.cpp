// Practica realizada por Blanca Macazaga Zuazo y Adrián Alcántara Delgado
#include "GlobosPG.h"
using namespace std;


GlobosPG::GlobosPG(juegoPG* juego, int &px, int &py)
{
	x = px; //posicion en el eje x e y del globo
	y = py;
	
	game = juego; //puntero a la clase juegoPG
	alto = ancho = 100; //tamaño del globo
	explotado = false; 
	invisible = false;
	puntos = 5; //puntos iniciales

	inflado = 100; //inicialmente el globo está totalmente inflado
}


//--------------------------------------------------------------------------------//
void GlobosPG::draw() {
	if (!invisible){
		ObjetoPG::draw();
	}
}
//--------------------------------------------------------------------------------//
bool GlobosPG::onClick(){
	//comprueba si se ha explotado el globo en el rectangulo de la imagen
	if (dentro(x, y)){
		invisible = true;
		return explotado = true;
		juego->newBaja(this);
		juego->newPuntos(puntos);
	}
	else return false;
}
//--------------------------------------------------------------------------------//
//actualiza el globo
void GlobosPG::update(){
	//si se ha deshinchado o se ha explotado el globo ya no sera visible 
	if (inflado == 0 || explotado)
		invisible = true;
	else {
		if (rand() % 100 < PVIS) //probabilidad de que sea visible o no
			invisible = false;
		else
			invisible = true;

		if (rand() % 100 < PDES){ //probabilidad de que se desinfle
			inflado -= 10; //disminuye el "aire" que tiene el globo
			alto -= 10; //disminuye el tamaño del globo
			ancho -= 10;
			//aumentan los puntos que se recibe al explotar el globo cuanto menos inflado este
			puntos += 2;
		}
		
	}
}

//getter de puntos del globo
int GlobosPG::getPuntos(){
	return puntos;
}

//--------------------------------------------------------------------------------//
GlobosPG::~GlobosPG()
{

}
