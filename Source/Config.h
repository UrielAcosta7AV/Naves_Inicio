#ifndef _CONFIG_H_
#define _CONFIG_H_
					  // movimientos binarios //
#define BORDE_IZQUIERDO		1<<0  //ESTE 0001 //
#define BORDE_DERECHO		1<<2  //ESTE 0010//
#define BORDE_INFERIOR		1<<3  //ESTE 0100//
#define BORDE_SUPERIOR		1<<4  //ESTE 1000 //
#define WIDTH_SCREEN 640
#define HEIGHT_SCREEN 480

#define FPS_LIMIT 30.0f
#define FPS_DELAY 1000.0f / FPS_LIMIT
//#define SPRITE_MODULE_MI_NAVE  0
    /*
#define BORDE_IZQUIERDO  1<<0  //ESTE 0001 //
#define BORDE_SUPERIOR   1<<1  //ESTE 0010//
#define BORDE_DERECHO    1<<2  //ESTE 0100//
#define BORDE_INFERIOR   1<<3  //ESTE 1000 // 
#define WIDTH_SCREEN 640
#define HEIGHT_SCREEN 480
#define SPRITE_MODULE_MI_NAVE  0
	*/


<<<<<<< HEAD
	*/
///////////////////////SPRITES//////////////////////
/*
TIPO_NOMBRE(Archivo)_DESCRIPCION
*/
//MODULO_MINAVE_NAVE
#define MODULO_MINAVE_NAVE      		 0
#define MODULO_MENU_FONDO				 1
#define MODULO_ENEMIGO_NAVE			     2
#define MODULO_TEXTO_TITULO				 3
#define MODULO_TEXTO_NOMBRE				 4
#define MODULO_TEXTO_OPCION1			 5
#define MODULO_TEXTO_OPCION2			 6
#define MODULO_TEXTO_OPCION1_SELECCION   7
#define MODULO_TEXTO_OPCION2_SELECCION   8
#define MODULO_BALAS_BALA1               9
#define MODULO_TEXTO_ANIO               10

#define MENU_NUMERO_ELEMENTOS			 MODULO_TEXTO_OPCION1_SELECCION-MODULO_TEXTO_OPCION1       

/**************************/

#define MAXIMO_BALAS                     500

#define NAVE_PROPIA                      0
#define NAVE_ENEMIGO                     1
=======
>>>>>>> origin/master
 
#endif
