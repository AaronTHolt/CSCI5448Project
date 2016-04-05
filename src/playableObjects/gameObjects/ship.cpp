#include "ship.h"
#include "objectLoader/waveOBJ.h"
#include "shipPhysicsObject.h"

#include <QString>
#include <QMessageBox>
#include <iostream>

Ship::Ship() : GameObject()
{
    physicsObject = new ShipPhysicsObject();

    // F-16
    f16=nullptr;
    try
    {
        f16 = new WaveOBJ("f-16.obj",":/");
    }
    catch (QString err)
    {
        // Fatal("Error loading object\n"+err);
        // QMessageBox::critical(this,"Ship",err);
        // QApplication::quit();
    }

    //Is this necessary/in the right place?
    if (f16)
    {
        f16->color(1,1,0);
    }
}

Ship::~Ship()
{
    delete f16;
}

// void Ship::thrust(){
//     physicsObject->applyForce();
// }

// void Ship::pitch(bool pitchUp){
//     physicsObject->applyRotationPitch(pitchUp);
// }

// void Ship::yaw(bool yawRight){
//     physicsObject->applyRotationYaw(yawRight);
// }

// void Ship::fireDefaultWeapon(){
//     defaultWeapon->fire();
// }

// void Ship::fireAuxiliaryWeapon(){
//     auxiliaryWeapon->fire();
// }

void Ship::draw() const{
    //see ex01 -> WaveOBJ.cpp
    f16->display();
}
