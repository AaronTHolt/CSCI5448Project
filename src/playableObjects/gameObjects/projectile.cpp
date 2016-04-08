#include "projectile.h"


Projectile::Projectile(int t){
	// physicsObject = new projectilePhysicsObject();
    int type;
    type = t;
    if (type == 0){
        proj = new Cube(1,1,1,0.1,0.1,0.1,0);
    }
	
}

Projectile::~Projectile(){
    delete proj;
}

// void Projectile::onCollision(){
// 	weapon.returnBullet();
// }

void Projectile::setIsInPlay(bool exists){
    isInPlay = exists;
}

bool Projectile::getIsInPlay(){
    return isInPlay;
}

void Projectile::draw(){
    proj->draw();
}