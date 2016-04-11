#include "projectile.h"

#include <iostream>


Projectile::Projectile(int t, int bn, Vector3 p, Vector3 v, Vector3 f) : GameObject()
{
    velocity = &v; //Was going to be used to help determine starting velocity, but currently is not.
    p = p + 1.7*f;
    position = &p; 
    f = 7*f;
    forward = &f;

	physicsObject = new ProjectilePhysicsObject(*position, *forward);

    bulletNumber = bn;

    type = t;
    if (type == 0){
        proj = new Cube(position->getX(),position->getY(),position->getZ(),0.1,0.1,0.1,0);
    }
	
}

Projectile::~Projectile(){
    delete proj;
}

// void Projectile::onCollision(){
// 	weapon.returnBullet();
// }

void Projectile::setPosition(const Vector3* p){
    position = p;
}

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