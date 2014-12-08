#include "Nave.h"
#include "Config.h"
#include "Sprite.h"

Nave::Nave(SDL_Surface * screen, char * rutaImagen, int x, int y, int module){
	moduleUsing=module;
	//+5
	sprite->borrarFondoNave();
	//-5

<<<<<<< HEAD
void Nave::Pintar(){
	 nave->Pintar();
};

Nave::Nave(SDL_Surface * screen, char * rutaImagen, int x, int y, int module){
	nave = new Objeto(screen, rutaImagen, x, y, module);
	bala = new Objeto *[MAXIMO_BALAS];
	for(int i = 0; i<MAXIMO_BALAS;i++){

	bala[i] = new Objeto(screen, "../Data/balas.bmp", 0,0,MODULO_BALAS_BALA1);
	bala[i]->SetVisible(false);

	}
	balasVisibles=0; 
=======
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
>>>>>>> origin/master

}

<<<<<<< HEAD
void Nave::MoverIzquierda(int valor){
	nave->MoverIzquierda(valor);
}

void Nave::MoverDerecha(int valor){
	nave->Mover(valor);
}

void Nave::MoverArriba(int valor){
	nave->MoverArriba(valor);
}

void Nave::MoverAbajo(int valor){
	nave->MoverAbajo(valor);
}

Objeto * Nave::GetNaveObjeto(){
	return nave;
}

void Nave::Disparar(int tipo, int valor){
	bala[balasVisibles]->SetVisible(true);
	switch(tipo)
	{
	case NAVE_PROPIA:
	         bala[balasVisibles]->ponerEn(nave->obtenerX()+nave->obtenerW()/2,nave->obtenerY());
	         break;
	case NAVE_ENEMIGO:
		bala[balasVisibles]->ponerEn(nave->obtenerX()+nave->obtenerW()/2,nave->obtenerY()+nave->obtenerH());
			 break;
=======
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
>>>>>>> origin/master
	}
	balasVisibles++;
	if(balasVisibles>=MAXIMO_BALAS)
		balasVisibles=0;
}
<<<<<<< HEAD

void Nave::Actualizar(int tipo, int valor){
	  for(int i=0;i<MAXIMO_BALAS;i++)
	{
		bala[i]->Pintar();	
		switch(tipo)
		{
		case NAVE_PROPIA:
			bala[i]->MoverArriba(valor);//CODIGO PARA MOVER ARRIBA
			break;
		case NAVE_ENEMIGO:
			bala[i]->MoverAbajo(valor);//CODIGO PARA MOVER ABAJO
			break;
	     }
	 }  

}
void Nave::AutoDisparar(int efectividad, int valor)
{
	if(rand()%100<efectividad)
	Disparar(NAVE_ENEMIGO, valor);
}
=======
	
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
>>>>>>> origin/master
