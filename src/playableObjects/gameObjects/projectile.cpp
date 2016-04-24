#include "projectile.h"
#include "world.h"

#include <iostream>


Projectile::Projectile(int t, const Vector3& p, const Vector3& f, const Vector3& v, Weapon* w) : GameObject()
{
    this->w = w;
    Vector3 tempf = 2.2*f;
    Vector3 pos = p + tempf;
    Vector3 forward = 7*f;

    physicsObject = new ProjectilePhysicsObject(pos, forward, v, this);

    type = GameObjectType::Projectile;
    
    proj = nullptr;
    projectileType = t;
    if (projectileType == 0){
        proj = new Cube(0,0,0,0.1,0.1,0.1,0);
    }
	
}

Projectile::~Projectile(){
    if (proj != nullptr){
        delete proj;
    }
    
}

bool Projectile::onCollision(GameObjectType got){
    switch(got){
        case GameObjectType::Ship:
            return true;
        default:
            if (w!=nullptr){
                w->returnBullet();
            }
            World::getWorld().lock()->deregisterGameObject(this);
            break;
    }
    return false;
}




void Projectile::setIsInPlay(bool exists){
    isInPlay = exists;
}

bool Projectile::getIsInPlay(){
    return isInPlay;
}

void Projectile::draw() const{

    glPushMatrix();
    float* rotMatrix = new float[16];
    physicsObject->getRotationMatrix(rotMatrix);
    glMultMatrixf(rotMatrix);
    proj->draw();
    glPopMatrix();
    delete rotMatrix;
}
