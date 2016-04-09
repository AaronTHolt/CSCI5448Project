#include "basicWeapon.h"
#include "cube.h"
#include "projectile.h"

#include <iostream>

BasicWeapon::BasicWeapon(): Weapon()
{
    for (unsigned int i=0; i<bulletCount; i++){
        Bullet[i] = new Projectile(0);
    }
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

	//create new projectile
	Bullet[bulletCount]->draw();
    // Bullet[2]->draw();
}
