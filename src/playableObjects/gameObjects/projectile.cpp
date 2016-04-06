#include "projectile.h"
#include "cube.h"

Projectile::Projectile(int type){
	// physicsObject = new projectilePhysicsObject();

    if (type == 0){
        proj = new Cube(1,1,1,1,1,1,0);
    }
	
}

Projectile::~Projectile(){
    delete proj;
}

void Projectile::onCollision(){
	weapon.returnBullet();
}

bool Projectile::isInPlay(){

}

void Projectile::draw(){
    proj->draw();
}