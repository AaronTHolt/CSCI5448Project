#include "projectile.h"



Projectile::Projectile(int t){
    velocity = new Vector3(1.0,1.0,1.0);
    position = new Vector3(1.0,0.0,0.0);

	physicsObject = new ProjectilePhysicsObject(*position, *velocity);

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

// Vector3 getPosition(){
//     return position;
// }

// Vector3 getVelocity(){
//     return velcotiy;
// }

void Projectile::draw(){
    proj->draw();
}