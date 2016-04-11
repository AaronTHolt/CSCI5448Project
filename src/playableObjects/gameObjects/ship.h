#ifndef _SHIP_H_
#define _SHIP_H_

#include "gameObject.h"
#include "objectLoader/waveOBJ.h"
#include "weapon.h"



class Ship: public GameObject{
    private:
        Weapon* basicWeapon;
    //     Weapon auxiliaryWeapon;
    //     Health health;
        // void Fatal(QString message);            //  Error handler
        WaveOBJ* f16;
    public:
        Ship();
        ~Ship();

        void thrust();
        void pitch(bool pitchUp);
        void yaw(bool yawRight);
        void fireDefaultWeapon();
        // void fireAuxiliaryWeapon();

        void draw() const;
        // void draw(WaveOBJ* ship);

	bool onCollision(GameObjectType got);
};


#endif
