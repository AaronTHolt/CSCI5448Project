#include "projectile.h"
#include "cube.h"

Projectile::Projectile(){
	// physicsObject = new projectilePhysicsObject();
	// cube(1,0,0,1,1,1,0);
}

void Projectile::onCollision(){
	weapon.returnBullet();
}