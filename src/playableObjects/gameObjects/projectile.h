#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "gameObject.h"
#include "weapon.h"
#include "cube.h"
#include "projectilePhysicsObject.h"
#include "vector3.h"

class Projectile: public GameObject{
	private:
        bool isInPlay;
        int type;
        


    public:
		Projectile(int t, Vector3 p, Vector3 v, Vector3 f);
        ~Projectile();
		// void onCollision();
        void draw() const;
        void setPosition(const Vector3* p);
        void setIsInPlay(bool exists);
        bool getIsInPlay();

        Cube* proj;
        const Vector3* position;
        const Vector3* velocity;
        const Vector3* forward;

        



		

};

#endif