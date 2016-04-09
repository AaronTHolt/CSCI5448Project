#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "weapon.h"
#include "cube.h"
#include "projectilePhysicsObject.h"
#include "vector3.h"

class Projectile{
	private:
        bool isInPlay;
        PhysicsObject* physicsObject;
        Vector3* position;
        Vector3* velocity;
    public:
		Projectile(int t);
        ~Projectile();
		// void onCollision();
        void draw();

        Cube* proj;

        void setIsInPlay(bool exists);
        bool getIsInPlay();

        // Vector3 getPosition();
        // Vector3 getVelocity();

		

};

#endif