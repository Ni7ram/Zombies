#include "Viewport.h"

Viewport::Viewport(int XC, int YC){
    X = XC;
    Y = YC;
};

Viewport::~Viewport(){};

//***********************************************
//              OTHER FUNCTIONS
//***********************************************

bool Viewport::translate(float x, float y){
     //CONVERT COORDINATES     
};

void Viewport::shake(int strength){
     //SHAKE CAMERA
     if (strength>2){ //SI ES MENOR NO PUEDE HACER EN RAND Y SE ROMPE TODO
         //X += rand()%(strength/2);
         //Y += rand()%(strength/2);
     }
};

void Viewport::zoom(float factor){
     //ZOOM
};

void Viewport::operator=(const Viewport& v2){
     X = v2.X;
     Y = v2.Y;
};

void Viewport::setTarget(float x, float y){
	X = x;
	Y = y;
};

float Viewport::getX() const{
	return X;
};

float Viewport::getY() const{
	return Y;
};
