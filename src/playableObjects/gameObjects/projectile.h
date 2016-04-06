#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "weapon.h"

class Projectile{
	private:
        bool isInPlay();
    public:
		Projectile();
        ~Projectile();
		void onCollision();
        void draw();

        Cube* proj;

		

};

#endif