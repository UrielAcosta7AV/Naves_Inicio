#ifndef __NAVE_H__
#define __NAVE_H__
#include "Objeto.h"

class Nave 
{
	Objeto *nave;
	Objeto **bala;
	int balasVisibles;

public:
	Nave(SDL_Surface * screen, char *rutaImagen, int x, int y, int module);
	void Pintar();
	void Disparar(int tipo, int valor);
	void AutoDisparar(int tipo, int valor);//metodo y nos vamos a nave.cpp
	void Actualizar(int tipo, int valor);
	void Nave::MoverDerecha(int valor);	
	void Nave::MoverIzquierda(int valor);
	void Nave::MoverArriba(int valor);
	void Nave::MoverAbajo(int valor);
	Objeto*GetNaveObjeto();
};
/*
class Nave{


};
*/
#endif