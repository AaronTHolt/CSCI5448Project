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
        int bulletNumber; //keep track of which bullet to delete
        Cube* proj;
        
    public:
		Projectile(int t, int bn, Vector3 p, Vector3 f);
        ~Projectile();
		// void onCollision();
        void draw() const;
        void setIsInPlay(bool exists);
        bool getIsInPlay();
        int getBulletNumber();

        


        



		

};

#endif