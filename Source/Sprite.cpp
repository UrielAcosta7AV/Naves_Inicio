#include "Sprite.h"
#include "SDL.h"
#include "SpriteDef.h"



void Sprite::CargarImagen(char * path){
image = SDL_LoadBMP(path);
}/////////////////

Sprite::Sprite(SDL_Surface * screen){
this->screen = screen;
};/////////////

Sprite::~Sprite(){
SDL_FreeSurface(image);
};


void Sprite::PintarModulo(int nombre, int x, int y){
SDL_Rect src;
src.x = SpriteDef.modulos[nombre].x;
src.y = SpriteDef.modulos[nombre].y;
src.w = SpriteDef.modulos[nombre].w;
src.h = SpriteDef.modulos[nombre].h;

	SDL_Rect dest;
dest.x = x;
dest.y = y;
SDL_BlitSurface(image, &src, screen, &dest);
};///////////////////////