#include "Nave.h"
#include "Config.h"
#include "Sprite.h"

Nave::Nave(SDL_Surface * screen, char * rutaImagen, int x, int y, int module){
	moduleUsing=module;
	//+5
	sprite->borrarFondoNave();
	//-5

	sprite = new Sprite(screen);
	sprite->CargarImagen(rutaImagen);
	w=sprite->WidthModule(moduleUsing);//variables para los modulos//
	h=sprite->HeightModule(moduleUsing);

	this->x=x;//Aqui se corto la direccion y se coloco en Game.cpp nave//
	this->y=y;//
	stepsActual=0;
	posicionBrinco=0;
	posicionActual=0;
}
Nave::~Nave()
{
	delete sprite;
}

void Nave::Pintar()
{
	sprite->PintarModulo(moduleUsing,x,y);
}

void Nave::Mover(int posicion)
{
	x += posicion;
}

void Nave::MoverIzquierda(int posicion)
{
	x -= posicion;
}

void Nave::MoverArriba(int posicion)
{
	y -= posicion;
}

void Nave::MoverAbajo(int posicion)
{
	y += posicion;
}

int Nave::obtenerX()
{
	return x;
}

int Nave::obtenerY(){
	return y;
}

int Nave::obtenerW()
{
	return w;
}

int Nave::obtenerH(){
	return h;
}
void Nave::ponerEn(int x, int y)
{
	this->x=x;
	this->y=y;
}

void Nave::Mover(int brinco, int puntoFinal)
{
	if(posicionBrinco<=0)
	{
		posicionBrinco=brinco;
		posicionFinal=puntoFinal;
	}
}

void Nave::Actualizar()
{
	if(posicionBrinco !=0)
	{
		if(posicionActual<=posicionFinal)
		{
		Mover(posicionBrinco);
		posicionActual++;
		}
		else{
				/*
			    posicionBrinco=0;//
				posicionActual=0;//
				posicionFinal=0;//
				IncrementarStep();//
				*/
			TerminarAnimacion();
		}
	}
}
	
void Nave::SetStep(int stepsFinal)//Aqui se habilitan los metodos//
{
	this->stepsFinal=stepsFinal;
}
void Nave::IncrementarStep()
{
	stepsActual++;
		if(stepsActual>=stepsFinal)
			stepsActual=0;
}
int Nave::ObtenerStepActual()
{
	return stepsActual;
}
bool Nave::IsRunningAnimacion()
{
	if(posicionBrinco==0)
		return false;
	else
		return true;
}
void Nave::TerminarAnimacion(){///Aqui terminamos animacion & pasamos al siguiente paso.....
		posicionBrinco=0;
		posicionFinal=0;
		posicionActual=0;
		IncrementarStep();
}
