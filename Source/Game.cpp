#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL_image.h>
#include <SDL.h>

CGame::CGame()
{
	estado = ESTADO_INICIANDO;//Corregido Maestro//
	atexit(SDL_Quit);

	//ACT3: Mal, este codigo va en el metodo "Iniciando()"
	///ACT3: Mal, el codigo de abajo debe estar en el metodo iniciando, revisa el documento de la actividad3.
	//if (SDL_Init(SDL_INIT_VIDEO)){
	//	printf("Error %s ", SDL_GetError());
	//	exit(EXIT_FAILURE);	
	//
	//}

	//screen = SDL_SetVideoMode(640, 480, 24, SDL_SWSURFACE);

	//if (screen == NULL){
	//	printf("Error %s ", SDL_GetError());
	//	exit(EXIT_FAILURE); 
	//}

	//SDL_Flip(screen);
	//SDL_WM_SetCaption("Mi primer Juego", NULL);
}

//ACT3: Mal, te falto este metodo.
void CGame::Iniciando()
{
	if (SDL_Init(SDL_INIT_VIDEO)){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);	

	}

	screen = SDL_SetVideoMode(640, 480, 24, SDL_SWSURFACE);

	if (screen == NULL){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE); 
	}

	SDL_WM_SetCaption("Mi primer Juego", NULL);
}

void CGame::Finalize()
{
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
	while (salirJuego == false)
	{

		//Maquina de estados
		switch(estado)
		{
		case Estado::ESTADO_INICIANDO: 
			Iniciando();//ACT3: Mal, Falto mandar a llamar este metodo
			estado=ESTADO_MENU;
			break;//ACT2: Mal, falto el break.
		case Estado::ESTADO_MENU:
			{
				nave = SDL_LoadBMP("../Data/MiNave.bmp");

				SDL_Rect Fuente;  
				Fuente.x = 90;
				Fuente.y = 152;
				Fuente.w = 242;
				Fuente.h = 76;
				SDL_Rect destino;
				destino.x = 100;
				destino.y = 100;
				destino.w = 100;
				destino.h = 100;

				SDL_BlitSurface(nave, &Fuente, screen, &destino);

				SDL_BlitSurface(nave, NULL, screen, NULL);

				SDL_FreeSurface(nave);
			}

			break;
		case Estado::ESTADO_JUGANDO:
			break;
		case Estado::ESTADO_FINALIZADO:
			break;
		case Estado::ESTADO_TERMINANDO: 
			salirJuego = true;
			break;
		};
		SDL_Flip(screen);// imprimir en pantalla la variable screen
	}
	return true;
}
