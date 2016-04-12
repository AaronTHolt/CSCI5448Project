#include "basicWeapon.h"
#include "cube.h"
#include "projectile.h"
#include "physicsWorld.h"
#include "ship.h"

#include <iostream>

BasicWeapon::BasicWeapon(): Weapon()
{
    numFired = 0;
}

BasicWeapon::~BasicWeapon(){
}

//Adds projectiles back after collisions.
void BasicWeapon::returnBullet(){
    numFired--;
}

void BasicWeapon::fire(Vector3 p, Vector3 f){

    if (numFired >= bulletCount){
        return;
    }

    Projectile *proj = new Projectile(0, p, f);

    std::weak_ptr<World> theWorld;
    theWorld = World::getWorld();

    if (auto spt = theWorld.lock())  // Has to be copied into a shared_ptr before usage
    {
        spt->registerGameObject(proj);
        numFired++;
    }
}

