#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame() 
{
	estado = ESTADO_INICIANDO; 
	atexit(SDL_Quit);
}
void CGame::Iniciando(){
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		printf("Error: %s",SDL_GetError());
		exit(EXIT_FAILURE);
	}
	//screen = SDL_SetVideoMode(640,480,24,SDL_SWSURFACE);//
	screen = SDL_SetVideoMode( WIDTH_SCREEN, HEIGHT_SCREEN, 24,SDL_SWSURFACE);
	if (screen == NULL)
	{
		printf("Error: %s",SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_Flip (screen); 
	SDL_WM_SetCaption( "Mi Primer Juego", NULL);
	atexit(SDL_Quit);

	nave= new Nave(screen,"../Data/MiNave.bmp",(WIDTH_SCREEN/2)/*-(w/2)*/,(HEIGHT_SCREEN-80)/*-(h)*/);
	//enemigo = new Nave(screen,"../Data/enemigo.bmp",0,0);

	enemigoArreglo = new Nave*[10];

	for(int i = 0; i<10;i++)
	{
		enemigoArreglo[i] = new Nave(screen,"../Data/enemigo.bmp",i*65,i*65);
	}
	
//	enemigo->SetStep(4);//
	for(int i = 0; i<10;i++)
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
	int bandera = 0;

	while (salirJuego == false)
	{
	
		switch(estado)
		{
		case Estado::ESTADO_INICIANDO: 
			
			Iniciando();
		    printf("\n1. ESTADO_INICIANDO");
			estado = ESTADO_MENU;
			break;
		case Estado::ESTADO_MENU:	
			SDL_FillRect(screen, NULL, 0x000000); 
			keys = SDL_GetKeyState(NULL);

				for(int i = 0; i<10;i++)
				{
					enemigoArreglo[i]->Actualizar();
				}
			MoverEnemigo();
			if(keys[SDLK_RIGHT] && !esLimitePantalla(nave,BORDE_DERECHO)) 
			{
				nave->Mover(1);				
			}					
			nave->Pintar();

			for(int i = 0; i<10;i++)
			{
				enemigoArreglo[i]->Pintar();
			}


		
			break;
		case Estado::ESTADO_JUGANDO:	//JUGAR//
		
			estado = ESTADO_TERMINADO;
			break;
		case Estado::ESTADO_TERMINADO:	//TERMINAR//
	
   		 	 //estado = ESTADO_FINALIZADO;//
			 
			
			
		  	break;
		case Estado::ESTADO_FINALIZADO: //SALIR//
			
		

			getchar();
			salirJuego = true;
			break;
		};//------------Fin del switch

		while (SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT){salirJuego = true;}//Si se detecta una//
			if(event.type == SDL_KEYDOWN){}
		}
		SDL_Flip(screen); //imprime en pantalla variable screen//
	}
	return true;
}

bool CGame::esLimitePantalla(Nave *objeto, int bandera)//metodo para limitar la pantalla//
{
	if(bandera & BORDE_IZQUIERDO) //CTRL + ESPACIO// & para valores binarios y 
	   if (objeto->obtenerX() <= 0)//revisar bordes falso o verdadero//
	      return true;
	if(bandera & BORDE_SUPERIOR)
    	if(objeto->obtenerY() <= 0) 
	     	return true;
	if(bandera & BORDE_DERECHO)
    	if(objeto->obtenerX() >= (WIDTH_SCREEN-objeto->obtenerW()))
	    	return true;
	if(bandera & BORDE_INFERIOR)
    	if(objeto->obtenerY() >= (HEIGHT_SCREEN-objeto->obtenerH()))
	    	return true;
		return false;// si se cumplen todas las condiciones quiere decir que estamos adentro de la pantalla//
}

void CGame::MoverEnemigo()//Metodo para mover al enemigo//
{
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
	for(int i=0;i<10;i++)
		switch(enemigoArreglo[i]->ObtenerStepActual())
	{
	 case 0:
		 

		  if(!enemigoArreglo[i]->IsRunningAnimacion())
			  enemigoArreglo[i]->Mover(1,WIDTH_SCREEN-enemigoArreglo[i]->obtenerW());	
			 //  enemigo->IncrementarStep();	

		   if(esLimitePantalla(enemigoArreglo[i],BORDE_DERECHO))/////////PARA QUE SALGA DE PANTALLA////
			  enemigoArreglo[i]->TerminarAnimacion();/////////PARA QUE SALGA DE PANTALLA////
		break;
	 case 1:
		

		 enemigoArreglo[i]->IncrementarStep();
		break;
	 case 2:
		   if(!enemigoArreglo[i]->IsRunningAnimacion())
		 enemigoArreglo[i]->Mover(-1,WIDTH_SCREEN-enemigoArreglo[i]->obtenerW());
		 // enemigo->IncrementarStep();////

		    if(esLimitePantalla(enemigoArreglo[i],BORDE_IZQUIERDO))/////////
			  enemigoArreglo[i]->TerminarAnimacion();
		break;
	 case 3:
		  enemigoArreglo[i]->IncrementarStep();
		break;

	}
	
}
