#ifndef __SPRITE_H__
#define __SPRITE_H__
#include<SDL.h>
#include "SpriteDef.h"

class Sprite{
SDL_Surface * image;//Imagen//
SDL_Surface * screen;//Pantalla//
SpriteDef spriteDef;
public:
void CargarImagen(char * path);
void PintarModulo(int nombre, int x, int y);
Sprite(SDL_Surface * screen);//Constructor//
~Sprite();//Destructor//




};



#endif