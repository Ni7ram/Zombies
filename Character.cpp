#include "Character.h"

Character::Character(double x, double y) : DrawObject(x,y,2), life(100){
    X = x;
    Y = y;
};

Character::~Character(){
};

//***********************************************
//              OTHER FUNCTIONS
//***********************************************

void Character::draw(){};

void Character::goUp(){
	if(legalMovement(X, Y - vel)){
    	Y -= vel;
	}
};
void Character::goDown(){
	if(legalMovement(X, Y  + vel)){
 	   Y += vel;
	}
};
void Character::goRight(){
	if (legalMovement(X + vel, Y)){
        X += vel;
	}
 };
void Character::goLeft(){
	if(legalMovement(X - vel, Y)){
        X -= vel;
	}
};

bool Character::legalMovement(double x, double y) const {
	if (x > leftLimit && x < rightLimit && y > upperLimit && y < bottomLimit){
		return true;
	}else{
		return false;
	}
};

//***********************************************
//              GETTERS/SETTERS
//***********************************************
void Character::setLife(int new_life){if(new_life < 100) life = new_life;};
int Character::getLife() const {return life;};

double Character::getX() const {return X;};
double Character::getY() const {return Y;};
