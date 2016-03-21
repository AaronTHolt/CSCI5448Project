#ifndef _HEALTH_H_
#define _HEALTH_H_

#include "gameObject.h"

class Health{
    private:
        long numLives;
        long shieldStrength;
        long hp;

    public:
        //Return false if not dead, true if dead(all lives lost)
        bool takeDamage(long damage);
        //Just check if dead only
        bool isDead();
};


#endif
