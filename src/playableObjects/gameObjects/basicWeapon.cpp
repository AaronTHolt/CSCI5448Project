#include "basicWeapon.h"
#include "cube.h"
#include "projectile.h"
#include "physicsWorld.h"
#include "ship.h"


#include <iostream>

BasicWeapon::BasicWeapon(): Weapon()
{
    bulletCount = 3;
    // for (unsigned int i=0; i<bulletCount; i++){
        
    // }
}

BasicWeapon::~BasicWeapon(){
}

//Adds projectiles back after collisions.
void BasicWeapon::returnBullet(){
	//destroy collided projectile
	// delete Bullet[bulletCount];

    if (bulletCount < 3){
        bulletCount += 1;
    }
	
}

void BasicWeapon::fire(Vector3 p, Vector3 v, Vector3 f){

    if (bulletCount >= 1){
        bulletCount -= 1;

        Bullet[bulletCount] = new Projectile(0, v, p, f);

        // std::cout << x << " " << y << " " << " " << z << std::endl;
        // std::cout << x << " " << y << " " << " " << z << std::endl;

        std::weak_ptr<World> theWorld;
        theWorld = World::getWorld();

        if (auto spt = theWorld.lock())  // Has to be copied into a shared_ptr before usage
        {
            spt->registerGameObject(Bullet[bulletCount]);
        }
    }
	

	
}

