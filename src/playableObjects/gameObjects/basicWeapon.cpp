#include "basicWeapon.h"

basicWeapon::~BasicWeapon(){}

basicWeapon::BasicWeapon(){

}

//Adds projectiles back after collisions.
basicWeapon::returnBullet(){
	//destroy collided projectile
	delete Bullet[bulletCount];

	bulletCount += 1;
}

basicWeapon::fire(){
	bulletCount -= 1;

	//create new projectile
	Bullet[bulletCount] = new Projectile(BasicWeapon weapon);
}

