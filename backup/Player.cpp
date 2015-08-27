#include "Player.h"

Player::Player(double x, double y) : Character(x,y){
    vel  = 2;    
	Character::size = size;   
};

Player::~Player(){};

//***********************************************
//              OTHER FUNCTIONS
//***********************************************

void Player::reload(){};

void Player::update(){
	checkInput();
	updateInercia();
};

void Player::draw(){    
    double correctedX = X - CAMERA->getX();
	double correctedY = Y - CAMERA->getY();
	
	//GRAPHIC
    circlefill(CANVAS, (int)correctedX, (int)correctedY, size, makecol(50,50,200));  
    circlefill(CANVAS, (int)correctedX-1, (int)correctedY-1, size-2, makecol(90,90,220));  
    circlefill(CANVAS, (int)correctedX-2, (int)correctedY-2, size-4, makecol(130,130,250));  
    circlefill(CANVAS, (int)correctedX-3, (int)correctedY-3, size-6, makecol(200,200,240));  
    circlefill(CANVAS, (int)correctedX-4, (int)correctedY-4, size-8, makecol(240,240,255));
    circle(CANVAS, (int)correctedX, (int)correctedY, size, makecol(0,0,0));    
};

void Player::checkInput(){
	Helper myHelper;
	
    //-MOVEMENT-//
    if (key[KEY_W]) {
	   if (myHelper.abs(inerciaY) < inerciaSpeedLimit){
   	   	   inerciaY -= inerciaInc * 4;
	   }
 	   goUp(); 
    }
    if (key[KEY_S]) {
	   if (myHelper.abs(inerciaY) < inerciaSpeedLimit){
   	   	   inerciaY += inerciaInc * 4;
    	}
	   goDown(); 
   }
    if (key[KEY_D]) {
       if (myHelper.abs(inerciaX) < inerciaSpeedLimit){
   	   	   inerciaX += inerciaInc * 4;
	   }
 	   goRight(); 
   	}
    if (key[KEY_A]) {
	   if (myHelper.abs(inerciaX) < inerciaSpeedLimit){
   	   	   inerciaX -= inerciaInc * 4;
	   }
   	   goLeft(); 
	}
};

void Player::updateInercia(){
	//IF LEGAL, MOVE; IF NOT BOUNCE ON WALL (or whatever)
	if(legalMovement(X + inerciaX, Y)){
        X += inerciaX;
	}else{
		inerciaX = -inerciaX;
	}
	
	if(legalMovement(X, Y + inerciaY)){
	    Y += inerciaY;
	}else{
		inerciaY = -inerciaY;
	}
	
 	//INERCIA DECAY
    if(inerciaY > 0){inerciaY -= inerciaInc;}else if(inerciaY < 0){inerciaY += inerciaInc;}
    if(inerciaX > 0){inerciaX -= inerciaInc;}else if(inerciaX < 0){inerciaX += inerciaInc;}
};
