#ifndef __PLAYER
#define __PLAYER

#include "Character.h"
#include "Helper.h"

class Player : public Character{
	public:
		Player(double x, double y);
	 	~Player();
	 	
	 	//FUNCTIONS
		void reload();
    	void update();
		void draw();
		void checkInput();
		
	protected:		
		//STATIC PROPERTIES
		static const float inerciaSpeedLimit = 6;
	    static const int size = 35;
	    
	    //FUNCTIONS
    	void updateInercia();
	    
	    //VARS
		int currentAmmo = 0;
};

#endif //__PLAYER
