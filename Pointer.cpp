#include "pointer.h"

Pointer::Pointer(int x, int y):Bullet(x,y,3,3){};

//***********************************************
//              OTHER FUNCTIONS
//***********************************************

void Pointer::draw(){
    Y = mouse_y;
    X = mouse_x;

    circlefill(CANVAS, (int)X, (int)Y, 2, makecol(255,255,255));
    circle(CANVAS, (int)X, (int)Y, 5, makecol(255,0,0)); 
};
