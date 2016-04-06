#include "basicWeapon.h"
#include "cube.h"

#include <iostream>

BasicWeapon::BasicWeapon(): Weapon()
{
}

BasicWeapon::~BasicWeapon(){
}

//Adds projectiles back after collisions.
void BasicWeapon::returnBullet(){
	//destroy collided projectile
	// delete Bullet[bulletCount];

	bulletCount += 1;
}

void BasicWeapon::fire(){

	bulletCount -= 1;
	Cube* cc = new Cube(1,1,1,2,2,2,0);
    cc->draw();
	//create new projectile
	// Bullet[bulletCount] = new Projectile(BasicWeapon weapon);
}

