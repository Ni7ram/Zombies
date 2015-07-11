#include "ZombieRapido.h"

ZombieRapido::ZombieRapido(double x, double y):Zombie(x,y){};

ZombieRapido::~ZombieRapido(){};

//***********************************************
//              OTHER FUNCTIONS
//***********************************************

void ZombieRapido::update(const double &xPlayer, const double &yPlayer){
	//X = xPlayer + rand()%50;
	vel = 6- (((xPlayer-X)*(xPlayer-X) + (yPlayer-Y)*(yPlayer-Y)) / 8000 );
	if (vel>4) vel=4;
	if (vel<0) vel=0;
    Zombie::update(xPlayer, yPlayer);
	draw();
};
