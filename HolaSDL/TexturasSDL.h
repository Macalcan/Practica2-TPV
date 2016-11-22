// Practica realizada por Blanca Macazaga Zuazo y Adrián Alcántara Delgado
#pragma once
#include "SDL.h"
#include <string>
using namespace std;

class TexturasSDL
{
public:
	TexturasSDL();
	~TexturasSDL();
	void draw(SDL_Renderer* pRenderer, SDL_Rect const& rect);
	bool load(SDL_Renderer* pRenderer, string const& nombArch);
private:
	int alto; //alto de la superficie de la textura
	int ancho; //ancho de la superficie de la textura
	SDL_Surface* loadFile(string file);
	SDL_Texture* pTextura;
};

