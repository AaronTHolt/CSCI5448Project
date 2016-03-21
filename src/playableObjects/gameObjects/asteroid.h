#ifndef _ASTEROID_H_
#define _ASTEROID_H_

#include "gameObject.h"

class Asteroid: public GameObject{
    private:
        int asteroidSize;

    public:
        void draw();
};


#endif