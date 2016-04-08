#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "weapon.h"
#include "cube.h"

class Projectile{
	private:
        bool isInPlay;
    public:
		Projectile(int t);
        ~Projectile();
		// void onCollision();
        void draw();

        Cube* proj;

        void setIsInPlay(bool exists);
        bool getIsInPlay();

		

};

#endif