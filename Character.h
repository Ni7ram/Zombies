#ifndef __CHARACTER
#define __CHARACTER

#include "DrawObject.h"

class Character : public DrawObject{
	public:
		Character(double x, double y);
        ~Character();
		
		//FUNCTIONS
		void setLife(int);
		void draw();
		
		//GETTERS/SETTERS
		int getLife() const;
		double getX() const;
		double getY() const;
		        
       //STATIC PROPERTIES
        static int upperLimit;
        static int bottomLimit;
        static int leftLimit;
        static int rightLimit;
				
	protected:	    
	    //FUNCTIONS
        void goUp();
		void goDown();
		void goRight();
		void goLeft();
		bool legalMovement(double x, double y) const;
		
		//STATIC PROPERTIES
		static const float inerciaInc = .07f;
		
		//VARS
		int life;        
        float vel;        
   		double inerciaX;
		double inerciaY;
};

#endif //__/CHARACTER
