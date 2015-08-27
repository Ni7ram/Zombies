#ifndef __VIEWPORT
#define __VIEWPORT

class Viewport {   
    public:        
        Viewport(int XC, int YC);
        ~Viewport();
    
    	//FUNCTIONS
        bool translate(float x, float y);
        void shake(int strength);
        void zoom(float factor);
        void setTarget(float x, float y);
        
        //GETTERS/SETTERS
        float getX() const;
        float getY() const;
        
        //OPERATOR OVERLOADS
        void operator=(const Viewport&);
        
    protected:
    	//VARS
     	float X;
        float Y;
};

#endif // __VIEWPORT
