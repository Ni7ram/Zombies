#include "Grid.h"

Grid::Grid(int sizeC):DrawObject(-sizeC/2,-sizeC/2,1){
	gridSize = sizeC;
    X = -gridSize/2;
    Y = -gridSize/2;
	discoMode = true;	
    
    //TODO: GET FROM AN EXTERN TXT
	cells = 15; 	
	cellsSeparation = 5; //px UNITS
	
	//BUILD
	buildMatrix();
};

Grid::~Grid(){
    destroyMatrix();
};

//***********************************************
//              OTHER FUNCTIONS
//***********************************************

void Grid::buildMatrix(){
	cellSize = (gridSize/cells) - cellsSeparation;
	margin = (int) (gridSize - (cells*(cellSize + cellsSeparation)))/2; //IF STAGE WIDTH ISN'T A MULTIPLE OF CELL SIZE, AN EXTRA BORDER APPEARS

	//DINAMICALLY CREATES THE GRID MATRIX							                                                  
    cellsArray = new int*[cells];
    for(int i = 0; i < cells; i++){
    	*(cellsArray + i) = new int[cells];
	    for(int j = 0; j < cells; j++){    	
   		    cellsArray[i][j] = 0;
		}
	}
};

void Grid::destroyMatrix(){
	for(int i = 0; i < cells; i++){
    	delete[] *(cellsArray + i);
	}
	delete[] cellsArray;
};

void Grid::draw(BITMAP *dest){
	CANVAS = dest;
 	double correctedX = X - CAMERA->getX();
	double correctedY = Y - CAMERA->getY();
	
	//CELLS
    for (int i = 0; i < cells; i++){
        for (int j = 0; j < cells; j++){    
            if (discoMode){
            	float _x = correctedX + margin + (i * (cellSize + cellsSeparation));
            	float _y = correctedY + margin + (j * (cellSize + cellsSeparation));
			    rectfill(dest, (int)_x, (int)_y, (int)(_x + cellSize), (int)(_y + cellSize), makecol(25 + cellsArray[i][j], 25 + cellsArray[i][j], 35 + cellsArray[i][j]));
			    //DISCO EFFECT DECAY
          	    if (cellsArray[i][j]>0) cellsArray[i][j] -= discoFadeRatio;
			}else{
         	   rectfill(dest, 
	                    (int)(correctedX + i * cellSize + margin), 
		                (int)(correctedY + j * cellSize + margin), 
						(int)(correctedX + i * cellSize + cellsSeparation), 
						(int)(correctedY + j * cellSize + cellsSeparation), 
						makecol(15,15,30));
			}
        }
	}
	
	//BORDER
	rect(dest, (int)correctedX, (int)correctedY, (int)(correctedX + gridSize), (int)(correctedY + gridSize), makecol(180,180,255));
};

void Grid::highlight(int x, int y){
	int cellToHighlightX = (int)((x + (gridSize/2)) / (cellSize + cellsSeparation));
	int cellToHighlightY = (int)((y + (gridSize/2)) / (cellSize + cellsSeparation));
	
	//cellToHighlight En |cellsArray|
	if (cellToHighlightX >= 0 && cellToHighlightX < cells && cellToHighlightY >= 0 && cellToHighlightY < cells){
		cellsArray[cellToHighlightX][cellToHighlightY] = 100;
	}
};

void Grid::fade(int value){     
    fadeValue = value;     
    fading    = true;
};

bool Grid::setMode(int value){
	if(value >= 0 && value <= 2){
		mode = value;
		return true;
	}
	return false;
};

void Grid::moreCells(){
	if(cells < 30){
		destroyMatrix();
	 	cells++;	
	 	buildMatrix();
    }
};

void Grid::lessCells(){
	if(cells > 1){
		destroyMatrix();
	    cells--;
	    buildMatrix();
	}
};
