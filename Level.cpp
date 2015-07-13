#include "Level.h"

Level::Level(int width, int height){
	STAGE_WIDTH  = width;
	STAGE_HEIGHT = height;
		
	grid = new Grid(stageSize);
};

Level::~Level(){	
};

//***********************************************
//              OTHER FUNCTIONS
//***********************************************

void Level::init(){		
	//CREATES PLAYER, BUFFER and MOUSE POINTER
    buffer  = create_bitmap(STAGE_WIDTH, STAGE_HEIGHT);
    player  = new Player(0,0);   	
    pointer = new Pointer(0, 0);
    
    //CREATES CAMERA AND SET IT ON PLAYER COORDS
	camera  = new Viewport(0, 0);
    camera->setTarget(player->getX() - player->getSize()/2 - STAGE_WIDTH/2, player->getY() - player->getSize()/2 - STAGE_HEIGHT/2);
    
	//ALL DrawOjbect INSTANCES ARE DRAW ON THE SAME BITMAP
    DrawObject::CANVAS = buffer;
    DrawObject::CAMERA = camera;
    
    //SET BOUNDARIE LIMIT FOR CHARACTERS AND BULLETS
    Bullet::upperLimit  = -stageSize/2;
    Bullet::bottomLimit = stageSize/2;
    Bullet::leftLimit   = -stageSize/2;
    Bullet::rightLimit  = stageSize/2;
    /***********************************************/
    Character::upperLimit  = -stageSize/2;
    Character::bottomLimit = stageSize/2;
    Character::leftLimit   = -stageSize/2;
    Character::rightLimit  = stageSize/2;
    /***********************************************/

    dreamMode = false;

	//INPUT FLAGS (KEYBOARD AND MOUSE)
	clicking = false;
	zPressed = false;
	kPressed = false;
	pPressed = false;

	//AUTOMATIC SHOOTING MODE
    automatic = 1;		

    //SYSTEM CLOCK (used to normalize game speed)
    timer.init();
};

void Level::update(){
	//RENDER MODE
    if(dreamMode){
       set_trans_blender(0, 0, 0, 20);
       drawing_mode(DRAW_MODE_TRANS, 0, 0, 0);
       rectfill(buffer, 0, 0, STAGE_WIDTH, STAGE_HEIGHT, makecol(5,5,15));
       set_trans_blender(0, 0, 0, 255);  	
       drawing_mode(DRAW_MODE_SOLID, 0, 0, 0);
	}else{
 	   rectfill(buffer, 0, 0, STAGE_WIDTH, STAGE_HEIGHT, makecol(5,5,15));
    }

    /**************************************************************************
                     THIS BLOCK LOCKS THE GAME TO 90 FPS
    **************************************************************************/
	timer.reset();
    while(timer.GetEllapsedTime()<11){ //11 miliseconds per frame equals 90 fps
    	//DO NOTHING (IN THE FUTURE USE FOR UPDATE ARTIFICIAL INTELLIGENCE)
    }
    timer.reset();
    /*************************************************************************/
    
    //NOW UPDATE
	updateGame();
};

void Level::updateGame(){
    checkInput();
    checkCollisions();
        
	//UPDATE PLAYER
    player->update();
    
    //UPDATES CAMERA
    if(cameraFollowing){
   	    camera->setTarget(player->getX() - player->getSize()/2 - STAGE_WIDTH/2, player->getY() - player->getSize()/2 - STAGE_HEIGHT/2);
    }
    
    //UPDATE ZOMBIES
    zombieManager.update(player->getX(), player->getY());
	
    //UPDATE BULLETS    
    for(int i = 0; i < arBullets.size(); i++){
        arBullets[i]->update();
        if((arBullets[i])->isReadyToDelete()){
            delete arBullets[i];
            arBullets.erase(arBullets.begin() + i);
            i--;
        }
    }
    
    //DISCO FLOOR
    grid->highlight((int)player->getX(),(int)player->getY());
    grid->draw(buffer);
        
    //DRAW SHADOWS
	zombieManager.drawShadows();
    player->drawShadow();
    for(int i = 0; i < arBullets.size(); i++){arBullets[i]->drawShadow();} //BULLETS SHADOWS
    
    //DRAW SPRITES
    for(int i = 0; i < arBullets.size(); i++){arBullets[i]->draw();}
	zombieManager.draw();
    player->draw();
    
	//DRAW GUI ELEMENTS
    drawGUI();
};

void Level::checkInput(){
    //MOUSE CLICK ROUTINE
    if(mouse_b&1 && !clicking){
        shoot();
	}else if(!mouse_b&1){
        clicking = false;
    }
    
    //ADD 3 ZOMBIES
    if (key[KEY_Z] && !zPressed){
        zombieManager.addZombie();  
        zPressed = true;
    }else if(!key[KEY_Z]){
        zPressed = false;
    }
    
    //AUTOMATIC SWITCH
    if (key[KEY_K] && !kPressed){
        if (automatic == 1){
            automatic = 0;
        }else{
            automatic = 1;
        }
        kPressed = true;
    }else if(!key[KEY_K]){
        kPressed = false;
    }
    
    //CAMERA FOLLOWING ON/OFF
    if (key[KEY_C] && !cPressed){
        cameraFollowing = !cameraFollowing;
        cPressed = true;
    }else if(!key[KEY_C]){
        cPressed = false;
    }    
    
    //GRID CELLs ADJUST
    if (key[KEY_ENTER] && !enterPressed){
        grid->moreCells();
        enterPressed = true;
    }else if(!key[KEY_ENTER]){
        enterPressed = false;
    }
    if (key[KEY_BACKSPACE] && !backspacePressed){
        grid->lessCells();
        backspacePressed = true;
    }else if(!key[KEY_BACKSPACE]){
        backspacePressed = false;
    }
    
    //CHANGE RENDER MODE (DREAM MODE ON/OFF)
    if (key[KEY_P] && !pPressed){
        dreamMode = !dreamMode;
        pPressed = true;
    }else if(!key[KEY_P]){
        pPressed = false;
    }
};

void Level::shoot(){
	//CALCULATE ANGLE BETWEEN PLAYER AND MOUSE
	float deltaX = mouse_x - (player->getX() - camera->getX());
	float deltaY = mouse_y - (player->getY() - camera->getY());	
   	float angle = atan2(deltaY, deltaX);

    float INCX  = cos(angle);
    float INCY  = sin(angle);

	//CREATE A BULLET IN THAT DIRECTION
    Bullet *newBullet = new Bullet(player->getX(), player->getY(), INCX, INCY);
    arBullets.push_back(newBullet);
    if (!automatic){
        clicking = true;          
    }
};

void Level::checkCollisions(){
	for (int j = 0; j< zombieManager.getZombieCount(); j++){
 	    ZombieRapido* zombie = zombieManager.getZombiesList(0)[j];
        for (int i = 0; i<arBullets.size(); i++){
            if (GHelper.hitArea(*arBullets[i], *zombie)){
                arBullets[i]->dispose();
                zombie->waste();                 
            }
        }
    }
};

void Level::drawGUI(){
    set_trans_blender(0, 0, 0, 100);
    drawing_mode(DRAW_MODE_TRANS, 0, 0, 0);
    rectfill(buffer, 0, 0, STAGE_WIDTH, 70, makecol(90,90,90));
    set_trans_blender(0, 0, 0, 255);  	
    drawing_mode(DRAW_MODE_SOLID, 0, 0, 0);

    textprintf_ex(buffer, font, 11, 11, makecol(0, 0, 0), -1, "Bullets: %i", arBullets.size()); 
    textprintf_ex(buffer, font, 10, 10, makecol(250, 200, 0), -1, "Bullets: %i", arBullets.size()); 
    
    textprintf_ex(buffer, font, 11, 23, makecol(0, 0, 0), -1, "Zombies: %i", zombieManager.getZombieCount());    
    textprintf_ex(buffer, font, 10, 22, makecol(245, 150, 0), -1, "Zombies: %i", zombieManager.getZombieCount());    
    
    textprintf_ex(buffer, font, 11, 35, makecol(0, 0, 0), -1, "Player: (%i,%i)", (int)player->getX(), (int)player->getY());
    textprintf_ex(buffer, font, 10, 34, makecol(235, 100, 0), -1, "Player: (%i,%i)", (int)player->getX(), (int)player->getY());
    
    camera = DrawObject::CAMERA;    
    textprintf_ex(buffer, font, 11, 47, makecol(0, 0, 0), -1, "Camera: (%i,%i)", (int)camera->getX(), (int)camera->getY());
    textprintf_ex(buffer, font, 10, 46, makecol(225, 50, 0), -1, "Camera: (%i,%i)", (int)camera->getX(), (int)camera->getY());
    
    textprintf_ex(buffer, font, 11, 59, makecol(0, 0, 0), -1, "Ammo: %i", 0);
    textprintf_ex(buffer, font, 10, 58, makecol(215, 20, 0), -1, "Ammo: %i", 0);

    /**************** DEL OTRO LADO ******************/

    textprintf_ex(buffer, font, 708, 11, makecol(0, 0, 0), -1, "Zombies (Z)");
    textprintf_ex(buffer, font, 707, 10, makecol(255, 200, 0), -1, "Zombies (Z)");
    
    textprintf_ex(buffer, font, 658, 31, makecol(0, 0, 0), -1, "Automatico (K): %i", automatic);
    textprintf_ex(buffer, font, 657, 30, makecol(245, 150, 0), -1, "Automatico (K): %i", automatic);
    
    textprintf_ex(buffer, font, 708, 51, makecol(0, 0, 0), -1, "Salir (ESC)");
    textprintf_ex(buffer, font, 707, 50, makecol(235, 100, 0), -1, "Salir (ESC)");
    
    pointer->draw();
    
    //BLIT FINAL BUFFER
    blit(buffer, screen, 0, 0, 0, 0, 800, 600);
};
