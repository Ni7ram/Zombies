#ifndef __ZOMBIE_RAPIDO
#define __ZOMBIE_RAPIDO

#include "Zombie.h"

class ZombieRapido : public Zombie{
	public: 
		ZombieRapido(double x, double y); //_
		~ZombieRapido();
		
		//FUNCTIONS
		void update(const double &xPlayer, const double &yPlayer);	
	protected:  
};

#endif //__ZOMBIE_RAPIDO
