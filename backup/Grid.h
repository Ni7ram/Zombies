#ifndef __GRID
#define __GRID

#include "DrawObject.h"

class Grid : public DrawObject{
public:
    //CONSTRUCTOR
    Grid(int sizeC);
    ~Grid();

    //FUNCTIONS 
    void draw(BITMAP*);   
    void fade(int); 
    void highlight(int x, int y);
    
    void buildMatrix();
    void destroyMatrix();
    void moreCells();
    void lessCells();
    
    //GETTERS/SETTERS
    bool setMode(int);
    
    //VARS
	BITMAP* CANVAS;  
    int cells;
    
private:
    //STATIC PROPERTIES
    static const int discoFadeRatio = 5;	

	//VARS
    float X;
    float Y;  
    int mode;
    int** cellsArray;
    int cellSize;
    int cellsSeparation;
    int margin;
    bool fading;
    bool discoMode;
    int fadeValue;
    int strenght;
    int gridSize;
};

#endif //__GRID
