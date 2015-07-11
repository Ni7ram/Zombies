#ifndef __HELPER
#define __HELPER

#include "DrawObject.h"
#include "Bullet.h"
#include "Zombie.h"

class Helper {
public:
    Helper();

    //FUNCTIONS
    bool hitArea(const Bullet& o1, const Zombie& o2) const;
    int outSideCoords(int min, int max) const;
    double abs(const double& a) const;
};

#endif //__HELPER
