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
        Weapon* w;
        
    public:
		Projectile(int t, Vector3 p, Vector3 f, Weapon* w = nullptr);
        ~Projectile();
		bool onCollision(GameObjectType got);
        void draw() const;
        void setIsInPlay(bool exists);
        bool getIsInPlay();

};

#endif