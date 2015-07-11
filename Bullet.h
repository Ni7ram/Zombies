#ifndef __Bullet
#define __Bullet

#include "DrawObject.h"

class Bullet : public DrawObject{      
    public:
        Bullet(double x, double y, double incX, double incY);
            
        //FUNCTIONS
        void update();
        void dispose();
        void draw() const;
    	bool outOfBoundaries() const;
        bool isReadyToDelete() const;
        void drawShadow() const;
        
        //STATIC PROPERTIES
        static int leftLimit;
        static int rightLimit;
        static int upperLimit;
        static int bottomLimit;
        
        //OPERATOR OVERLOADS
        void operator=(const Bullet&);
        bool operator==(const Bullet&)const;
        
    protected:                                 
	    //FUNCTIONS
        void calcPos();        
        
        //STATICS PROPERTIES
        static const int vel = 14;
   	    static const int size = 6;
        
        //VARS
        bool readyToDelete;
        double incX;
        double incY;	    
};
        
#endif //__Bullet
