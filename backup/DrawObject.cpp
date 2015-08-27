#include "DrawObject.h"

DrawObject::DrawObject(double x, double y, int depth):X(x),Y(y),ZDepth(depth),visible(true){
    sprite = new BITMAP;
};

DrawObject::~DrawObject(){
	delete sprite;
};

//***********************************************
//              OTHER FUNCTIONS
//***********************************************

void DrawObject::drawShadow() const{
	double correctedX = X - CAMERA->getX();
	double correctedY = Y - CAMERA->getY();
	
	//GRAPHIC
    circlefill(CANVAS, (int)correctedX + size/3, (int)correctedY + size/3, (int)(size*0.9f), makecol(0,0,20));  
};
        
//***********************************************
//              GETTERS/SETTERS
//***********************************************

double DrawObject::getX() const {return X;};
double DrawObject::getY() const {return Y;};
int DrawObject::getZDepth() const {return ZDepth;};
int DrawObject::getSize() const {return size;};

void DrawObject::setX(double new_x){X = new_x;};
void DrawObject::setY(double new_y){Y = new_y;};
void DrawObject::setZDepth(int new_depth){ZDepth = new_depth;};
