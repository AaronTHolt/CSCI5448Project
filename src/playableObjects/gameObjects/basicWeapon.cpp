#include "basicWeapon.h"
#include "cube.h"

#include <iostream>

BasicWeapon::BasicWeapon() : Weapon()
{
	std::cout << "HI!" << std::endl;
}

BasicWeapon::~BasicWeapon(){}

//Adds projectiles back after collisions.
void BasicWeapon::returnBullet(){
	//destroy collided projectile
	// delete Bullet[bulletCount];

	bulletCount += 1;
}

void BasicWeapon::fire(){

	bulletCount -= 1;
	// cube(1,1,1,0,0,0,0);
	//create new projectile
	// Bullet[bulletCount] = new Projectile(BasicWeapon weapon);
}

