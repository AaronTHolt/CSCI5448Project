#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "vector3.h"

class Weapon{
	public:
		virtual ~Weapon() = 0;
		virtual void fire(const Vector3& p, const Vector3& f, const Vector3& v) = 0;
        virtual void returnBullet();

};

#endif
