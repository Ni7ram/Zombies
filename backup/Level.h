#ifndef __LEVEL
#define __LEVEL

#include <vector>
#include <Math.h>
#include "DrawObject.h"
#include "Bullet.h"
#include "Character.h"
#include "Pointer.h"
#include "Player.h"
#include "Viewport.h"
#include "Grid.h"
#include "Helper.h"
#include "Timer.h"
#include "ZombieManager.h"

class Level{
	public:
		Level(int width, int height);
		~Level();
		
		//FUNCTIONS
		void init();
		void update();
		
	protected:
		//STATIC PROPERTIES
    	static const int stageSize = 700;
		
		//FUNCTIONS
		void drawGUI();
		void checkInput();
		void addZombie();
		void checkCollisions();
		void shoot();
		void updateGame();
			
		//VARS
		int STAGE_WIDTH;
		int STAGE_HEIGHT;
	
		Player* player;
		BITMAP* buffer;
		Timer timer;
			
		bool dreamMode;
		int automatic;
			
		bool clicking;
		bool zPressed;
		bool kPressed;
		bool pPressed;
		bool enterPressed;
		bool backspacePressed;
		bool cPressed;
		bool cameraFollowing;
		
		Pointer *pointer;
		Viewport* camera;			
		Grid* grid;
		Helper GHelper;

		ZombieManager zombieManager;
		std::vector<Bullet*> arBullets;
};

#endif //__LEVEL
