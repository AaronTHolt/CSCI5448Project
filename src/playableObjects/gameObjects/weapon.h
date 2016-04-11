#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "vector3.h"

class Weapon{
	public:
		virtual ~Weapon() = 0;
		virtual void fire(Vector3 p, Vector3 v, Vector3 f) = 0;

};

#endif