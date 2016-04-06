#ifndef _BASIC_WEAPON_H_
#define _BASIC_WEAPON_H_

#include "weapon.h"
#include "projectile.h"

class BasicWeapon: public Weapon{
	private:
		unsigned int bulletCount = 3;
		Projectile Bullet[3];

	public:
		BasicWeapon();
		~BasicWeapon();

		void fire();
		void returnBullet();

};

#endif
