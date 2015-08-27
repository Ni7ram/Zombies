#include "Helper.h"

Helper::Helper(){
};

//***********************************************
//              OTHER FUNCTIONS
//***********************************************

bool Helper::hitArea(const Bullet& o1, const Zombie& o2) const{
	 double X = o2.getX();
	 double Y = o2.getY();
	 double size = (double)o2.getSize();
	
	 double vertexX = o1.getX()-(o1.getSize()/2);
	 double vertexY = o1.getY()-(o1.getSize()/2);
     
     if (vertexX > X - (size/2) &&
	     vertexX < X + (size/2) && 
		 vertexY > Y - (size/2) && 
		 vertexY < Y + (size/2)){
         return true;
     }

	 vertexX = o1.getX() + (o1.getSize()/2);
	 vertexY = o1.getY() - (o1.getSize()/2);

     if (vertexX > X - (size/2) &&
	     vertexX < X + (size/2) && 
		 vertexY > Y - (size/2) && 
		 vertexY < Y + (size/2)){
         return true;
     }
	 
	 vertexX = o1.getX() - (o1.getSize()/2);
	 vertexY = o1.getY() + (o1.getSize()/2);
	 
     if (vertexX > X - (size/2) &&
	     vertexX < X + (size/2) && 
		 vertexY > Y - (size/2) && 
		 vertexY < Y + (size/2)){
         return true;
     }
     
	 vertexX = o1.getX()+(o1.getSize()/2);
	 vertexY = o1.getY()+(o1.getSize()/2);
	 
     if (vertexX > X - (size/2) &&
	     vertexX < X + (size/2) && 
		 vertexY > Y - (size/2) && 
		 vertexY < Y + (size/2)){
         return true;
     }
     
	 return false;
};

int Helper::outSideCoords(int min, int max) const{
    if (rand()%2){
       return (min-(rand()%100));
    }else{
       return (max+(rand()%100));
    }
};

double Helper::abs(const double& a) const{
    if(a>0){
    	return a;
	}else{
		return -a;
	}
};
