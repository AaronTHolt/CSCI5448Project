#ifndef _ASTEROID_H_
#define _ASTEROID_H_

#include "gameObject.h"
#include "vector3.h"
#include "waveOBJ.h"
#include "asteroidPhysicsObject.h"

class Asteroid: public GameObject{
    private:
        int asteroidSize;
        WaveOBJ* asteroid;

    public:
        Asteroid(Vector3 p);
        ~Asteroid();
        void draw() const;
        
};


#endif