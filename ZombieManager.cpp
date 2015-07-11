#include "ZombieManager.h"

ZombieManager::ZombieManager(){
};

ZombieManager::~ZombieManager(){
};

//***********************************************
//              OTHER FUNCTIONS
//***********************************************

void ZombieManager::update(double playerX, double playerY){
	 for(int i = 0; i < zombiesRapidosArray.size(); i++){
        zombiesRapidosArray[i]->update(playerX+5,playerY+5);
        if((zombiesRapidosArray[i])->isWasted()){
            delete zombiesRapidosArray[i];
            zombiesRapidosArray.erase(zombiesRapidosArray.begin() + i);
            i--;
        }
    }	
};

void ZombieManager::drawShadows() const{
    for(int i = 0; i < zombiesRapidosArray.size(); i++){zombiesRapidosArray[i]->drawShadow();}	
};

void ZombieManager::draw() const{
    for(int i = 0; i < zombiesRapidosArray.size(); i++){zombiesRapidosArray[i]->draw();}	
};
	
void ZombieManager::addZombie(){
	//RANDOMLY DECIDES IF THE ZOMBIE WILL APPEAR FROM TOP, LEFT, BOTTOM OF RIGHT
    int x = 0;
    int y = 0;
    int zone = rand() % 4; // 0 = arriba, 1 = derecha, 2 = abajo, 3 = izquierda
    switch(zone){
        case 0:
             y = rand()%50 - 100;
             x = rand()%600;
             break;
        case 1:
            x = 800 + rand()%50 + 100;
            y = rand()%800;
            break;
        case 2:
            y = 600 + rand()%50 + 100;;
            x = rand()%800;
            break;
        case 3:
            x = rand()%50 - 100;
            y = rand()%600;
            break;
    }
    
    //CREATES THE ZOMBIE
    ZombieRapido *newZombieRapido = new ZombieRapido(x,y);
    zombiesRapidosArray.push_back(newZombieRapido);
};

void ZombieManager::addZombie(int x, int y){ //ADS RAMDON ZOMBIE ON LOCATION
    //CREATES THE ZOMBIE
    ZombieRapido *newZombie = new ZombieRapido(x,y);
    
    zombiesRapidosArray.push_back(newZombie);
};

void ZombieManager::addZombie(int x, int y, int type){ //ADS EXPLICIT ZOMBIE ON LOCATION

};
  
void ZombieManager::addZombies(int new_zombies){ //ADS SOME RANDOM ZOMBIES
	 for(int i = 0; i < new_zombies; i++){
	 	addZombie();
	 }
};

void ZombieManager::addZombies(int cantZombies, int tipo){ //ADDS SOME EXPLICIT TYPE ZOMBIE
	 
};
 
//void ZombieManager::killAll()(
//);

void ZombieManager::freeze() const{
};

//***********************************************
//              GETTERS/SETTERS
//***********************************************

int ZombieManager::getZombieCount() const{
	return zombiesRapidosArray.size(); // + zombiesT2Array.size() + ... etc
};
	
std::vector<ZombieRapido*> ZombieManager::getZombiesList(int type) const{
	return zombiesRapidosArray;
};

