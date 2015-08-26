/************************************************
  Name: Juego_Loco
  Copyright: 
  Author: Martín Cardozo
  Date: 12/04/15 00:42
  Description: 
************************************************/

#include <allegro.h>

static const int WINDOW_WIDTH  = 1024;
static const int WINDOW_HEIGHT = 768;
static const bool FULLSCREEN   = false; //comentario 123

//MAIN LEVEL
#include "Level.h"
Level level0(WINDOW_WIDTH/1, WINDOW_HEIGHT/3);

//SOME CLASS INITIALIZATIONS
BITMAP* DrawObject::CANVAS;
Viewport* DrawObject::CAMERA;
int Character::upperLimit;
int Character::bottomLimit;
int Character::leftLimit;
int Character::rightLimit;
int Bullet::upperLimit;
int Bullet::bottomLimit;
int Bullet::leftLimit;
int Bullet::rightLimit;

//START ENGINE
void init();
void deinit();

//**********************************************/
//TODO: INCORPORAR INERCIA A PLAYER. [x]
//TODO: LIMITAR MOVIMIENTO A GRID. [x]
//TODO: EFECTO DISCO EN GRID. [x]
//TODO (el mas urgente): LEVANTAR ARCHIVO DE CONFIG (velocidades, tamaño de stage, disparo, etc). []
//TODO: HACERLO TIME-BASED. []
//TODO: HACER QUE LOS ZOMBIES SE MUEVAN BIEN (NO ANGULOS DE 45°). []
//TODO: HACER QUE LOS ZOMBIES CHOQUEN ENTRE SÍ. []
//TODO: EMPEZAR A CODIFICAR UNA MATRIZ DE OBSTACULOS EN GRID, Y CHECKEAR LOS BOUNDARIES PARA LIMITES, RAMPAS Y OBSTACULOS. []
//TODO: armar clase level y mandar todo ahi lo q noe s allegro
//*************************************************/

//MAIN FUNCTION
int main() {
	//INIT ENGINE AND GAME
	init();	
    level0.init();

	//GAME LOOP
	while (!key[KEY_ESC]) {   	
        level0.update();
	}
	
	//TERMINATE GAME
	deinit();
	return 0;
};
END_OF_MAIN()

//***************** ALLEGRO STUFF ******************/
void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	if(FULLSCREEN){
    	res = set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);	
    }else{
       	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);   
    }
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
};
void deinit() {
	clear_keybuf();
};
