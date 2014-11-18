#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"
#include "Nave.h"

CGame::CGame(){
	frames=0;
	tiempoFrameInicio=0;
	estado = Estado::ESTADO_INICIANDO;//ACT2: Mal, aqui debes de poner tu estado inicial, por eso te marcara error.
	atexit(SDL_Quit);
}
void CGame::Iniciando(){
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		printf("Error %S ", SDL_GetError());
		exit (EXIT_FAILURE);
	}
	//screen = SDL_SetVideoMode(640,480,24,SDL_SWSURFACE);//
	screen = SDL_SetVideoMode ( WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_HWSURFACE | SDL_DOUBLEBUF );
	if (screen == NULL)
	{
		printf("Error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_Flip (screen);
	SDL_WM_SetCaption( "N.A.V.I", NULL);
	atexit(SDL_Quit);
	nave = new Nave(screen, "../Data/MiNave.bmp",(WIDTH_SCREEN / 2)/*-(w/2)*/,(HEIGHT_SCREEN-80)/*-(h)*/,0);
	//enemigo = new Nave(screen,"../Data/enemigo.bmp",0,0);
	menu = new Nave(screen, "../Data/Texto.bmp",0,0,1);
	titulos= new Nave(screen,"../Data/espacio.bmp",0,0,1);
	fondo=new Nave(screen, "../Data/Fondo.bmp",0,0,1);

	enemigoArreglo = new Nave*[10];

	for	(int i=0;i<10;i++)
	{
		enemigoArreglo[i] =new Nave(screen, "../Data/enemigo.bmp",i*65,0,2);
	}

	//enemigo->SetStep(4);
	for (int i=0;i<10;i++)
	{
		enemigoArreglo[i]->SetStep(4);
	}

}


void CGame::Finalize(){
	SDL_Quit();
}

bool CGame::Start()
{
	
	int salirJuego = false;
          
	while (salirJuego == false){
            
		
		switch(estado)
		{
			case Estado::ESTADO_INICIANDO: 
			
				Iniciando();
			 //  printf("\n1. ESTADO_INICIANDO");
				estado=ESTADO_MENU;
				//estado = ESTADO_MENU;

				break;
			case Estado::ESTADO_MENU:
				
			//	menu->Pintar();
			//	titulos->Pintar();
				
				SDL_Flip (screen); 
				keys = SDL_GetKeyState(NULL);
				/*
				if(keys[SDLK_UP])
				{
				
					estado=ESTADO_JUGANDO;
				}
			
				if (keys[SDLK_DOWN])
				{
			
			
					estado=ESTADO_FINALIZADO;
				}
				*/
				estado=ESTADO_JUGANDO;
			
			break;
			
			case Estado::ESTADO_JUGANDO:	//JUGAR//
			SDL_FillRect(screen, NULL, 0x000000);
			keys = SDL_GetKeyState(NULL);

				for (int i=0;i<10;i++)
				{
					enemigoArreglo[i]->Actualizar();
				}

			MoverEnemigo();

			if(keys[SDLK_RIGHT]&& !esLimitePantalla(nave,BORDE_DERECHO))
			{

			//nave->PintarModulo(0,100,100);
			nave->Mover(8);
			///Iniciando();
				///estado=ESTADO_MENU;
			}
			//
			if(keys[SDLK_LEFT]&& !esLimitePantalla(nave,BORDE_IZQUIERDO)){
			nave->MoverIzquierda(8);
			}
			if(keys[SDLK_UP]&& !esLimitePantalla(nave,BORDE_SUPERIOR)){
			nave->MoverArriba(8);
			}
			if(keys[SDLK_DOWN]&& !esLimitePantalla(nave,BORDE_INFERIOR)){
			nave->MoverAbajo(8);
			}

			//fondo->Pintar();
			nave->Pintar();
	
			for (int i=0;i<10;i++)
			{
				enemigoArreglo[i]->Pintar();
			}
			//estado = ESTADO_TERMINADO;
			break;
			case Estado::ESTADO_TERMINADO:	//TERMINAR//

		    //estado = ESTADO_FINALIZADO;//
			break;
			case Estado::ESTADO_FINALIZADO:  //SALIR//

			//getchar();
			salirJuego = true;
			break;
		};//------------Fin del switch
				while (SDL_PollEvent(&event))
				{
					if (event.type == SDL_QUIT){salirJuego =true;}//si se detecta una//
						if (event.type == SDL_KEYDOWN){}
				}
		SDL_Flip(screen); //imprime en pantalla variable screen//

		frames++;
		tiempoFrameFinal = SDL_GetTicks();
		while(tiempoFrameFinal<(tiempoFrameInicio + FPS_DELAY)){
			tiempoFrameFinal =SDL_GetTicks();
		SDL_Delay(1);
		}
		printf("Frame:%d Tiempo:%d TiempoPorFrame:%d FPS:%f\n",frames, tiempoFrameInicio, tiempoFrameFinal-tiempoFrameInicio,1000.0f /(float)(tiempoFrameFinal-tiempoFrameInicio));
		tiempoFrameInicio= tiempoFrameFinal;
    }
	return true;
}
bool CGame::esLimitePantalla(Nave *objeto, int bandera){
	if(bandera & BORDE_IZQUIERDO) //CTRL + ESPACIO// & para valores binarios y 
		if (objeto->obtenerX() <=0)//revisar bordes falso o verdadero//
			return true;
	if(bandera & BORDE_SUPERIOR)
		if (objeto->obtenerY() <=0)
			return true;
	if(bandera & BORDE_DERECHO)
		if (objeto->obtenerX() >=(WIDTH_SCREEN-objeto->obtenerW()))
			return true;
	if(bandera & BORDE_INFERIOR)
		if (objeto->obtenerY() >=(HEIGHT_SCREEN-objeto->obtenerH()))
			return true;
	return false;// si se cumplen todas las condiciones quiere decir que estamos adentro de la pantalla//
}
void CGame::MoverEnemigo(){
// Aqui le damos movimiento x , y
	//if(!esLimitePantalla(enemigo, BORDE_DERECHO))  // Recordar f(x)=x^2  para garficar  f(x) | x^2
	//enemigo->Mover(1,50);  // el if y esto es lo que se cambia para moverlo diferente
	/*switch(enemigo->ObtenerStepActual())
	{
	 case 0:
		
		  if(!enemigo->IsRunningAnimacion())
			  enemigo->Mover(1,WIDTH_SCREEN-enemigo->obtenerW());
			 //  enemigo->IncrementarStep();
			
		break;
	 case 1:
		 enemigo->IncrementarStep();
		break;
	 case 2:
		   if(!enemigo->IsRunningAnimacion())
		 enemigo->Mover(-1,WIDTH_SCREEN-enemigo->obtenerW());
		 // enemigo->IncrementarStep();
		break;
	 case 3:
		  enemigo->IncrementarStep();
		break;

	}*/
	
	//enemigo->ponerEn(ennemigoParabola*ennemigoParabola,ennemigoParabola);////
	//ennemigoParabola+= 0.05f;//
	for (int i=0;i<10;i++)
		switch(enemigoArreglo[i]->ObtenerStepActual()){
	case 0:
		if(!enemigoArreglo[i]->IsRunningAnimacion())
			 //  enemigo->IncrementarStep();
		enemigoArreglo[i]->Mover(5,WIDTH_SCREEN-enemigoArreglo[i]->obtenerW());
		
	

		if(esLimitePantalla(enemigoArreglo[i],BORDE_DERECHO))/////////PARA QUE SALGA DE PANTALLA////
			enemigoArreglo[i]->TerminarAnimacion();/////////PARA QUE SALGA DE PANTALLA////

		break;
	case 1:
		enemigoArreglo[i]->IncrementarStep();
		break;
	case 2:
		 if (!enemigoArreglo[i]->IsRunningAnimacion())
		  enemigoArreglo[i]->Mover(-5,WIDTH_SCREEN-enemigoArreglo[i]->obtenerW());
		 // enemigo->IncrementarStep();////

		if(esLimitePantalla(enemigoArreglo[i],BORDE_IZQUIERDO))
			enemigoArreglo[i]->TerminarAnimacion();

		break;
	case 3:
		enemigoArreglo[i]->IncrementarStep();
		break;
	}

}