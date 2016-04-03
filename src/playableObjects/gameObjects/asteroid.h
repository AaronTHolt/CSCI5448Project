#ifndef _ASTEROID_H_
#define _ASTEROID_H_

#include "gameObject.h"
#include "objectLoader/waveOBJ.h"

class Asteroid: public GameObject{
    private:
        int asteroidSize;
        WaveOBJ* asteroid;

    public:
    	Asteroid();
        ~Asteroid();
        void draw() const;
};


#endif