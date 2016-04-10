#include "projectile.h"

#include <iostream>


Projectile::Projectile(int t, Vector3 p, Vector3 v, Vector3 f) : GameObject()
{
  // const Vector3 getForward() const;
  // const Vector3 getPosition() const;
  // const Vector3 getVelocity() const;
    // velocity = new Vector3(1.0,1.0,1.0);
    // position = new Vector3(1.0,0.0,0.0);
    velocity = &v;
    position = &p;
    forward = &f;

    

	physicsObject = new ProjectilePhysicsObject(*position, *velocity);

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

// Vector3 getPosition(){
//     return position;
// }

// Vector3 getVelocity(){
//     return velcotiy;
// }

void Projectile::draw() const{

    // If basic weapon
    if (type == 0){
        const Vector3* temp;
        temp = new Vector3(physicsObject->getPosition());
        proj->translate(temp->getX(),temp->getY(),temp->getZ());
    // std::cout << temp->getX() << temp->getY() << temp->getZ() << std::endl;
    }

    proj->draw();
}