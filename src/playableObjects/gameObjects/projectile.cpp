#include "projectile.h"

#include <iostream>


Projectile::Projectile(int t, int bn, Vector3 p, Vector3 f) : GameObject()
{

    Vector3 tempf = 1.7*f;
    p = p + tempf;
    f = 7*f;

	physicsObject = new ProjectilePhysicsObject(p, f);

    bulletNumber = bn;

    type = t;
    if (type == 0){
        proj = new Cube(p.getX(),p.getY(),p.getZ(),0.1,0.1,0.1,0);
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

int Projectile::getBulletNumber(){
    return bulletNumber;
}


void Projectile::draw() const{

    // If basic weapon
    if (type == 0){
        const Vector3* temp;
        temp = new Vector3(physicsObject->getPosition());
        proj->translate(temp->getX(),temp->getY(),temp->getZ());
    }

    proj->draw();
}