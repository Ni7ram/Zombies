#include "Zombie.h"
#include <Math.h>

Zombie::Zombie(double x, double y) : Character(x,y), wasted(false){
    DrawObject::size = size;
	tone = rand()%90;
    r = tone;
    b = tone;
    
    vel = 2;
    
    animState = 0; //0 = SPAWN, 1 = NORMAL
    animSpawn();
};

Zombie::~Zombie(){};

//***********************************************
//              OTHER FUNCTIONS
//***********************************************

void Zombie::update(const double &xPlayer, const double &yPlayer){	
    setTarget((int)xPlayer + rand()%50 - 25, (int)yPlayer + rand()%50 - 25);
    
    if (X < targetX){
        X += vel;
    }else{
        X -= vel;
    }
    if (Y < targetY){
        Y += vel;
    }else{
        Y -= vel;
    }
};

void Zombie::setTarget(int x, int y){
	targetX = x;
	targetY = y;	
};

void Zombie::draw(){
    double correctedX = X - CAMERA->getX();
	double correctedY = Y - CAMERA->getY();

	//GRAPHIC
	switch(animState){
		case 0: //SPAWN
	        animSpawn();
			break;
		case 1: //NORMAL
		    circlefill(CANVAS, (int)correctedX, (int)correctedY, size, makecol(r,g,b));
		    circlefill(CANVAS, (int)correctedX, (int)correctedY-1, size-2, makecol(tone+20, g+10, tone+20));  
		    circlefill(CANVAS, (int)correctedX, (int)correctedY-2, size-4, makecol(tone+40, g+20, tone+40));  
		    circlefill(CANVAS, (int)correctedX, (int)correctedY-3, size-6, makecol(tone+60, g+30, tone+60));  
		    circlefill(CANVAS, (int)correctedX, (int)correctedY-4, size-8, makecol(tone+80, g+40, tone+80)); 
		    circle(CANVAS, (int)correctedX, (int)correctedY, size, makecol(0,0,0));
			break;
		case 2: // DEAD
			break;
	}
};

void Zombie::waste(){
    wasted = true;
};

bool Zombie::isWasted() const{
    return wasted;
};

bool Zombie::legalMovement(float &x, float &y) const {
	if (x > leftLimit && x < rightLimit && y > upperLimit && y < bottomLimit){   
 	   return true;
	}else{
 	   return false;
	}
};

void Zombie::animSpawn(){
	animState = 1;
};
