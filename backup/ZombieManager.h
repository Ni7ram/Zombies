#ifndef __ZOMBIE_MANAGER
#define __ZOMBIE_MANAGER

#include "Zombie.h"
#include "ZombieRapido.h"
#include <vector>

class ZombieManager{
	public:
		ZombieManager();
		~ZombieManager();
		
		//FUNCTIONS
		void update(double, double);
		void drawShadows() const;
		void draw() const;
		
		void addZombie();
		void addZombie(int x, int y); //ZOMBIE ON LOCATION 
		void addZombie(int x, int y, int type); //WITH EXPLICIT TYPE
		void addZombies(int);
		void addZombies(int cantZombies, int tipo); //THIS ONE IS ALWAYS RANDOM

		//void killAll();
		void freeze() const;
		
		//GETTER/SETTERS
		int getZombieCount() const;		
		std::vector<ZombieRapido*> getZombiesList(int) const;		
		
	protected:		
		//ZOMBIE TYPES
		std::vector<Zombie*> zombiesArray;
		std::vector<ZombieRapido*> zombiesRapidosArray;
};

#endif //__ZOMBIE_MANAGER
