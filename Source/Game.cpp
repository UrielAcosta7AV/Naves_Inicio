#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"
<<<<<<< HEAD
#include "Objeto.h"
=======
#include "Nave.h"
>>>>>>> origin/master

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
	SDL_WM_SetCaption( "N.A.V.I 1.0", NULL);
	atexit(SDL_Quit);
<<<<<<< HEAD
	nave = new Nave(screen, "../Data/MiNave.bmp",(WIDTH_SCREEN / 2)/*-(w/2)*/,(HEIGHT_SCREEN-80)/*-(h)*/,MODULO_MINAVE_NAVE);
	//enemigo = new Nave(screen,"../Data/enemigo.bmp",0,0);
	menu = new Objeto(screen, "../Data/Texto.bmp",0,120,MODULO_TEXTO_TITULO	);//TEXTO INICIAR SALIR//TITULO//
	texto= new Objeto(screen,"../Data/Fondo.bmp",0,0,1);//FONDO de menu
	fondo=new Objeto(screen, "../Data/espacio.bmp",0,0,1);//fondo del juego
=======
	nave = new Nave(screen, "../Data/MiNave.bmp",(WIDTH_SCREEN / 2)/*-(w/2)*/,(HEIGHT_SCREEN-80)/*-(h)*/,0);
	//enemigo = new Nave(screen,"../Data/enemigo.bmp",0,0);
	menu = new Nave(screen, "../Data/Texto.bmp",0,120,1);//TEXTO INICIAR SALIR//TITULO//
	titulos= new Nave(screen,"../Data/Fondo.bmp",0,0,1);//FONDO de menu
	fondo=new Nave(screen, "../Data/espacio.bmp",0,0,1);//fondo del juego
>>>>>>> origin/master

	enemigoArreglo = new Nave*[10];

	for	(int i=0;i<10;i++)
	{
<<<<<<< HEAD
		enemigoArreglo[i] = new Nave(screen, "../Data/enemigo.bmp",i*65,0,MODULO_ENEMIGO_NAVE	);
=======
		enemigoArreglo[i] =new Nave(screen, "../Data/enemigo.bmp",i*65,0,2);
>>>>>>> origin/master
	}

	//enemigo->SetStep(4);
	for (int i=0;i<10;i++)
	{
		enemigoArreglo[i]->GetNaveObjeto()->SetStep(4);
	}
<<<<<<< HEAD
	menuSeleccion=MODULO_TEXTO_OPCION1;/////////////////////////////
=======
>>>>>>> origin/master

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
<<<<<<< HEAD
			InicializandoStage();
				Iniciando();
			 //  printf("\n1. ESTADO_INICIANDO");
				//estado=ESTADO_MENU;
				//estado = ESTADO_MENU;
				estado=ESTADO_MENU;

				break;
			case Estado::ESTADO_MENU:
			    texto->Pintar();
				menu->Pintar(MODULO_TEXTO_TITULO,160,30);/////////NAVI 1.0
				menu->Pintar(MODULO_TEXTO_NOMBRE,180,350);///////////ACOSTA
				menu->Pintar(MODULO_TEXTO_ANIO , 210, 420);//@2014
				menu->Pintar(MODULO_TEXTO_OPCION1, 320,150);//ENTRAR
				menu->Pintar(MODULO_TEXTO_OPCION2, 320, 200);//SALIR
				menu->Pintar(MODULO_TEXTO_OPCION1_SELECCION, 40, 150);//enter =
				menu->Pintar(MODULO_TEXTO_OPCION2_SELECCION, 40, 200);// ESC =
				

				//Menu();
				SDL_Flip (screen); 
				keys = SDL_GetKeyState(NULL);
				
				if(keys[SDLK_RETURN])
				{
				
					estado=ESTADO_PREJUGANDO;

				}
			
				if (keys[SDLK_ESCAPE])
				{
					estado=ESTADO_FINALIZADO;
				}
			
			
			break;

			case Estado::ESTADO_PREJUGANDO:
			nivelActual = 0;
			estado = ESTADO_JUGANDO;
			break;

=======
			
				Iniciando();
			 //  printf("\n1. ESTADO_INICIANDO");
				estado=ESTADO_MENU;
				//estado = ESTADO_MENU;

				break;
			case Estado::ESTADO_MENU:
			    titulos->Pintar();
				menu->Pintar();
								SDL_Flip (screen); 
				keys = SDL_GetKeyState(NULL);
				
				if(keys[SDLK_UP])
				{
				
					estado=ESTADO_JUGANDO;
				}
			
				if (keys[SDLK_DOWN])
				{
			
					estado=ESTADO_FINALIZADO;
				}
				
			break;
			
>>>>>>> origin/master
			case Estado::ESTADO_JUGANDO:	//JUGAR//
			SDL_FillRect(screen, NULL, 0x000000);
			keys = SDL_GetKeyState(NULL);

				for (int i=0;i<10;i++)
				{
					enemigoArreglo[i]->GetNaveObjeto()->Actualizar();
				}

			MoverEnemigo();
<<<<<<< HEAD
			
			if(keys[SDLK_RIGHT]&& !esLimitePantalla(nave->GetNaveObjeto(),BORDE_DERECHO))
			{

			//nave->PintarModulo(0,100,100);
			nave->MoverDerecha(niveles[nivelActual].velocidadPropia);
			
			///Iniciando();
				///estado=ESTADO_MENU;
			}
			if(keys[SDLK_SPACE]){
				nave->Disparar(NAVE_PROPIA, niveles[nivelActual].velocidadBalasPropia);
			}
			//
			if(keys[SDLK_LEFT]&& !esLimitePantalla(nave->GetNaveObjeto(),BORDE_IZQUIERDO)){
			nave->MoverIzquierda(niveles[nivelActual].velocidadPropia);
			}
			if(keys[SDLK_UP]&& !esLimitePantalla(nave->GetNaveObjeto(),BORDE_SUPERIOR)){
			nave->MoverArriba(niveles[nivelActual].velocidadPropia);
			}
			if(keys[SDLK_DOWN]&& !esLimitePantalla(nave->GetNaveObjeto(),BORDE_INFERIOR)){
			nave->MoverAbajo(niveles[nivelActual].velocidadPropia);
			}
			fondo->Pintar();
			nave->Pintar();
			nave->Actualizar(NAVE_PROPIA, niveles[nivelActual].velocidadBalasPropia);
			
				for(int i=0;i<10;i++){
				
			    enemigoArreglo[i]->AutoDisparar(niveles[nivelActual].velocidadBalasEnemigo,  MAXIMO_BALAS);/////
				enemigoArreglo[i]->Pintar();
				enemigoArreglo[i]->Actualizar(NAVE_ENEMIGO, niveles[nivelActual].velocidadBalasEnemigo);
	      	}
=======

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

			fondo->Pintar();
			nave->Pintar();
	
			for (int i=0;i<10;i++)
			{
				enemigoArreglo[i]->Pintar();
			}
>>>>>>> origin/master
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
<<<<<<< HEAD
bool CGame::esLimitePantalla(Objeto *objeto, int bandera){
=======
bool CGame::esLimitePantalla(Nave *objeto, int bandera){
>>>>>>> origin/master
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
<<<<<<< HEAD
		switch(enemigoArreglo[i]->GetNaveObjeto()->ObtenerStepActual()){
	case 0:
		if(!enemigoArreglo[i]->GetNaveObjeto()->IsRunningAnimacion())
			 //  enemigo->IncrementarStep();
		enemigoArreglo[i]->GetNaveObjeto()->Mover(niveles[nivelActual].velocidadEnemigo,WIDTH_SCREEN-enemigoArreglo[i]->GetNaveObjeto()->obtenerW());
		
	

		if(esLimitePantalla(enemigoArreglo[i]->GetNaveObjeto(),BORDE_DERECHO))/////////PARA QUE SALGA DE PANTALLA////
			enemigoArreglo[i]->GetNaveObjeto()->TerminarAnimacion();/////////PARA QUE SALGA DE PANTALLA////

		break;
	case 1:
		enemigoArreglo[i]->GetNaveObjeto()->IncrementarStep();
		break;
	case 2:
		 if (!enemigoArreglo[i]->GetNaveObjeto()->IsRunningAnimacion())
		  enemigoArreglo[i]->GetNaveObjeto()->Mover(-niveles[nivelActual].velocidadEnemigo,WIDTH_SCREEN-enemigoArreglo[i]->GetNaveObjeto()->obtenerW());
		 // enemigo->IncrementarStep();////

		if(esLimitePantalla(enemigoArreglo[i]->GetNaveObjeto(),BORDE_IZQUIERDO))
			enemigoArreglo[i]->GetNaveObjeto()->TerminarAnimacion();

		break;
	case 3:
		enemigoArreglo[i]->GetNaveObjeto()->IncrementarStep();
		break;
	}

}

void CGame::Menu(){
	for(int i = MODULO_TEXTO_OPCION1, j = 0; i <= MODULO_TEXTO_OPCION2; i++, j++)
	{
		if(i=menuSeleccion){
		texto->Pintar(MENU_NUMERO_ELEMENTOS,150,150+(j*50));
		}
		else
			texto->Pintar(1,150,150+(j*50));
	}

=======
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

>>>>>>> origin/master
}