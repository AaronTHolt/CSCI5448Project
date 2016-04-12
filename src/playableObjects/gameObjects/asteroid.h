#ifndef _ASTEROID_H_
#define _ASTEROID_H_

#include "gameObject.h"
#include "vector3.h"
#include "waveOBJ.h"
#include "asteroidPhysicsObject.h"

class Asteroid: public GameObject{
    public:
        enum class AsteroidSize{
            Small,
            Medium,
            Large,
        };

    private:
        AsteroidSize asteroidSize;
        WaveOBJ* asteroid;
        void split();


    public:
        Asteroid(Vector3 p, AsteroidSize size = AsteroidSize::Large);
        ~Asteroid();
        void draw() const;
	    bool onCollision(GameObjectType got);


};


#endif
