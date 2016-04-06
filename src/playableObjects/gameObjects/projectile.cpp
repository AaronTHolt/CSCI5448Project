#include "projectile.h"
#include "cube.h"

Projectile::Projectile(){
	// physicsObject = new projectilePhysicsObject();
}

void Projectile::onCollision(){
	weapon.returnBullet();
}