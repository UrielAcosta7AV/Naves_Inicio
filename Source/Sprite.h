#include <SDL.h>
#include "SpriteDef.h"


#ifndef _SPRITE_H_//evitar la redundancia
#define _SPRITE_H_


class Sprite{
	SDL_Surface *image;///////////////////
	SDL_Surface * screen;//Pantalla////////////////

	//SDL_Surface *screen;
	//SpriteDef spriteDef;
public:
	void CargarImagen(char * path);///////////////
	void PintarModulo(int nombre, int x, int y);/////////
	Sprite(SDL_Surface * screen);//Constructor
	~Sprite();//Destructor
	//void PintarModulo(int id, int x, int y);
	//Sprite(SDL_Surface * screen);
	//~Sprite();
	
};
#endif