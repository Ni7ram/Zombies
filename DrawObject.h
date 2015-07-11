#ifndef __DRAW_OBJECT
#define __DRAW_OBJECT

#include <allegro.h>
#include "Viewport.h" //OPCIONAL SI HAY CÁMARA

class DrawObject{
    public:
        DrawObject(double x, double y, int depth);
        ~DrawObject();
        
        //FUNCTIONS
        void drawShadow() const;
        
        //STATIC PROPERTIES
        static BITMAP* CANVAS;        
        static Viewport* CAMERA;
        
        //GETTERS/SETTERS
        void setX(double);
        void setY(double);
        void setZDepth(int);
        static void setDT(float);
        
        double getX() const;
        double getY() const;
        int getZDepth() const;     
        int getSize() const;
     	
    protected:        
        //VARS
        BITMAP* sprite;
        double X;
        double Y;
        int size;
        bool visible;
        int ZDepth;        
        int animState; //CUSTOM FOR EVERY INHERITANCE
};

#endif //__DRAW_OBJECT
