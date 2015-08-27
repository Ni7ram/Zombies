#include "Bullet.h"

Bullet::Bullet(double x, double y, double incX, double incY):DrawObject(x,y,2),incX(incX),incY(incY),readyToDelete(false){};

//***********************************************
//              OTHER FUNCTIONS
//***********************************************

void Bullet::update(){
    calcPos();
};

void Bullet::calcPos(){
	X += incX * vel;
    Y += incY * vel;

	if(outOfBoundaries()) readyToDelete = true;
};

void Bullet::drawShadow() const{
    double correctedX = X - CAMERA->getX();
	double correctedY = Y - CAMERA->getY();
	
	//GRAPHIC
    circlefill(CANVAS, (int)correctedX+8, (int)correctedY+8, size+2, makecol(0,0,20));
};

void Bullet::draw() const{
    double correctedX = X - CAMERA->getX();
	double correctedY = Y - CAMERA->getY();
	
	//GRAPHIC
    circlefill(CANVAS, (int)correctedX-2, (int)correctedY-2, size, makecol(255,0,0));    
    circlefill(CANVAS, (int)correctedX-2, (int)correctedY-2, size-1, makecol(255,200,200));
};

bool Bullet::isReadyToDelete() const {
    return readyToDelete;
};

bool Bullet::outOfBoundaries() const{
	if(X < leftLimit || X > rightLimit || Y < upperLimit || Y > bottomLimit){
		return true;
	}
	return false;
};

void Bullet::dispose(){
    readyToDelete = true;
};

//***********************************************
//              OPERATOR OVERLOADS
//***********************************************

void Bullet::operator=(const Bullet &Bullet2){
    X = Bullet2.X;
    Y = Bullet2.Y;
};

bool Bullet::operator==(const Bullet &Bullet2) const {
    if (X == Bullet2.getX() && Y == Bullet2.getY()){
        return true;
    }else{
        return false;
    } 
};
