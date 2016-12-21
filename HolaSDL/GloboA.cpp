// Practica realizada por Blanca Macazaga Zuazo y Adrián Alcántara Delgado
#ifndef _H_GloboA_H
#define _H_GloboA_H
#include "GloboA.h"
using namespace std;


GloboA::GloboA(juegoPG* jueg, juegoPG::Texturas_t texturas, int &px, int &py) :GlobosPG(jueg, texturas, px, py)
{
	//visible = true;
	/*visible = true;
	puntos = 0;
	explotado = false;
	inflado = 100;
	rectObjeto.h = rectObjeto.w = 100^*/
}


//--------------------------------------------------------------------------------//


//--------------------------------------------------------------------------------//
//actualiza el globo
void GloboA::update(){
	//si se ha deshinchado o se ha explotado el globo ya no sera visible 
	if (!explotado){
		if (inflado <= 0){
			explotado = true;
			visible = true;
			juego->newBaja(this);
		}
		else {

			if (rand() % 100 < PDES){ //probabilidad de que se desinfle
				inflado -= 10; //disminuye el "aire" que tiene el globo
				rectObjeto.h -= 10; //disminuye el tamaño del globo
				rectObjeto.w -= 10;
				
				//aumentan los puntos que se recibe al explotar el globo cuanto menos inflado este
				if (rectObjeto.y >= 40){
					puntos += 2;
					rectObjeto.y -= 40;
				}
				else
					puntos -= 2; //si pierde el doble de puntos que gana al desinflarse, directamente pierde dos puntos
			}

		}
	}
}




//--------------------------------------------------------------------------------//
GloboA::~GloboA()
{

}
#endif
