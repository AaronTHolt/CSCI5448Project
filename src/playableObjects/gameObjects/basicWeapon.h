#ifndef _BASIC_WEAPON_H_
#define _BASIC_WEAPON_H_

#include "weapon.h"
#include "projectile.h"
#include "world.h"

#include <memory>

class BasicWeapon: public Weapon{
	private:
		const int bulletCount = 3;
        int numFired = 0;

	public:
		BasicWeapon();
		~BasicWeapon();

		void fire(Vector3 p, Vector3 f);
		void returnBullet();
        int getNextFreeBullet();
};

#endif
