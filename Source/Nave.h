<<<<<<< HEAD
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
=======
#ifndef __NAVE_H__  //para proteger 
#define __NAVE_H__
#include "Sprite.h"

class Nave
{
	//Todas las variables
	int x;
	int y;
	int w;
	int h;
	int posicionActual;//donde esta la nave
	int posicionFinal;//asta donde llegara
	int posicionBrinco;
	int stepsActual;
	int stepsFinal;
	int moduleUsing;//Modulo en uso

Sprite * sprite;
public:
	Nave(SDL_Surface * screen, char * rutaImagen, int x, int y, int module);
	~Nave();
	//Aqui se crean todos los metodos//
	void Pintar();
	void Mover(int posicion);
		 //   cant      numero de veces//
	void MoverIzquierda(int posicion);
	void MoverArriba(int posicion);
	void MoverAbajo(int posicion);
	//
	void Mover(int brinco, int puntoFinal);
	void SetStep(int stepsFinal);
	void IncrementarStep();
	int ObtenerStepActual();
	void Actualizar();//Metodo de Actualizacion
	bool IsRunningAnimacion();
	void TerminarAnimacion();//fuerza a terminar la STRP actual de la nave//
	int obtenerX();//metodo para obtener el bvalor de x & y//
	int obtenerY();
	int obtenerW();
	int obtenerH();
	void ponerEn(int x, int y);

>>>>>>> origin/master
};
/*
class Nave{


};
*/
#endif