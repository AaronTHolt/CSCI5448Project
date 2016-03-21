#ifndef _SHIP_H_
#define _SHIP_H_

#include "gameObject.h"

class Ship{
    private:
        Weapon defaultWeapon;
        Weapon auxiliaryWeapon;
        Health health;

    public:
        void thrust();
        void pitch(bool pitchUp);
        void yaw(bool yawRight);
        void fireDefaultWeapon();
        void fireAuxiliaryWeapon();

        void draw();
};


#endif
