#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL_image.h>
#include <SDL.h>
#include "Config.h"
#include "Sprite.h"

CGame::CGame()
{
	estado = Estado::ESTADO_INICIANDO;
	atexit(SDL_Quit);
}
void CGame::Iniciando(){


	if (SDL_Init(SDL_INIT_AUDIO)){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);

	}

	screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_HWSURFACE);

	if (screen == NULL){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	//SDL_Flip(screen);
	//SDL_WM_SetCaption("Mi primer Juego", NULL);
	//nave = new Nave(screen, "../Data/minave.bmp");
	//nave->CargarImagen("../Data/minave.bmp");
}
void CGame::Finalize()
{
	SDL_Quit();
}

bool CGame::Start()
{
	/*EXAMEN 1ERCORTE
	Profesor comente algunas cosas del codigo para que solo apareciera la pantalla 
	del menu,, el codigo esta al dia. actualizado hasta El ultimo dia de clases
	*/
	int ban = 0;//Bandera Para Condicion...
	int salirJuego = false; char menu;// Esta variable nos ayudara a controlar la salida del juego...
	while (salirJuego == false)
	{
		//Maquina de estados
		switch (estado)
		{
		case Estado::ESTADO_INICIANDO:
			printf("\n1. ESTADO_INICIANDO");
		//	Iniciando();
			estado = ESTADO_MENU;
			break;
		case Estado::ESTADO_MENU:
			printf("\n2. ESTADO_MENU");
			if( ban > 0)
			{
				estado = ESTADO_FINALIZADO;
			}
			else
			{
				estado = ESTADO_JUGANDO;
			}
			/*
				SDL_FillRect(screen, NULL, 000000);
				keys = SDL_GetKeyState(NULL);
				if (keys[SDLK_RIGHT]){
					nave->Mover(10);
				}
				nave->Pintar();
				*/
			break;

		case Estado::ESTADO_JUGANDO:
			printf("\n3. ESTADO_JUGANDO");
			estado = ESTADO_TERMINANDO;
			break;

		case Estado::ESTADO_TERMINANDO:
			printf("\n4. ESTADO_TERMINANDO");
			ban=ban+1;
			estado = ESTADO_MENU;
			break;

		case Estado::ESTADO_FINALIZADO:
			printf("\n5. ESTADO_FINALIZADO");
			getchar();
			salirJuego = true;
			break;
		};
		/*
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT){ salirJuego = true; }
			if (event.type == SDL_KEYDOWN){}
		}
		*/
		//SDL_Flip(screen);// imprimir en pantalla la variable screen
	}
	return true;
}
