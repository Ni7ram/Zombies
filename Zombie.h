#ifndef __ZOMBIE
#define __ZOMBIE

#include "Character.h"

class Zombie : public Character{
    public:
        Zombie(double x, double y);
        ~Zombie();
    	
    	//FUNCTIONS
        void update(const double &xPlayer, const double &yPlayer);
        bool isWasted() const;
        void draw();
        void waste();
        
        //GETTERS/SETTERS
		void setTarget(int x, int y);

    protected:
    	//STATIC PROPERTIES
	    static const int size = 20;	    
        double vel = 2;
        
        //FUNCTIONS
		bool legalMovement(float &X, float &Y) const;
		void animSpawn();

        //VARS
    	int targetX;
    	int targetY;
    	
        bool wasted;
        
    	int tone;
    	int r;
    	static const int g = 150;
    	int b;
};

#endif //__ZOMBIE
