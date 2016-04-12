#ifndef _BASIC_WEAPON_H_
#define _BASIC_WEAPON_H_

#include "weapon.h"
#include "projectile.h"
#include "world.h"

#include <memory>

class BasicWeapon: public Weapon{
	private:
		int bulletCount;
		Projectile* Bullet[20];
        int freeBullets[20]; //0=free, 1=used
        int freeBullet;

	public:
		BasicWeapon();
		~BasicWeapon();

		void fire(Vector3 p, Vector3 f);
		void returnBullet(int bulletNumber);
        int getNextFreeBullet();
};

#endif
