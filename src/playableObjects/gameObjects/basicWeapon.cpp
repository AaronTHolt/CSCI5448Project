#include "basicWeapon.h"
#include "cube.h"
#include "projectile.h"
#include "physicsWorld.h"
#include "ship.h"

#include <iostream>

BasicWeapon::BasicWeapon(): Weapon()
{
    bulletCount = 20;
    for (int i = 0; i<bulletCount; i++){
        freeBullets[i] = 0;
    }
}

BasicWeapon::~BasicWeapon(){
}

//Adds projectiles back after collisions.
void BasicWeapon::returnBullet(int bulletNumber){
    freeBullets[bulletNumber] = 0; //show bullet as available
	delete Bullet[bulletNumber]; //destroy collided projectile
}

void BasicWeapon::fire(Vector3 p, Vector3 f){


    freeBullet = getNextFreeBullet();
    if (freeBullet < 0){ return; }

    freeBullets[freeBullet] = 1;
    Bullet[freeBullet] = new Projectile(0, freeBullet, p, f);

    std::weak_ptr<World> theWorld;
    theWorld = World::getWorld();

    if (auto spt = theWorld.lock())  // Has to be copied into a shared_ptr before usage
    {
        spt->registerGameObject(Bullet[freeBullet]);
    }
}

int BasicWeapon::getNextFreeBullet(){
    for (int i = 0; i<bulletCount; i++){
        if (freeBullets[i] == 0){
            return i;
        }
    }
    return -1;
}
