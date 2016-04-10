#include "ship.h"
#include "objectLoader/waveOBJ.h"
#include "shipPhysicsObject.h"
#include "basicWeapon.h"

#include <QString>
#include <QMessageBox>
#include <iostream>

Ship::Ship() : GameObject()
{
    physicsObject = new ShipPhysicsObject();
    basicWeapon = new BasicWeapon();

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

void Ship::thrust(){
  physicsObject->applyForce();
}

void Ship::pitch(bool pitchUp){
  physicsObject->applyRotationPitch(pitchUp);
}

void Ship::yaw(bool yawRight){
  physicsObject->applyRotationYaw(yawRight);
}

void Ship::fireDefaultWeapon(){
    const Vector3* tempPosition;
    tempPosition = new Vector3(physicsObject->getPosition());

    const Vector3* tempForward;
    tempForward = new Vector3(physicsObject->getForward());

    const Vector3* tempVelocity;
    tempVelocity = new Vector3(physicsObject->getVelocity());

    // float x = temp->getX();
    // float y = temp->getY();
    // float z = temp->getZ();
    // float fx = tempForward->getX();
    // float fy = tempForward->getY();
    // float fz = tempForward->getZ();
    basicWeapon->fire(*tempPosition, *tempVelocity ,*tempForward);

    delete tempPosition;
    delete tempForward;
    delete tempVelocity;
}

// void Ship::fireAuxiliaryWeapon(){
//     auxiliaryWeapon->fire();
// }

void Ship::draw() const{
  glPushMatrix();
  float* rotMatrix = new float[16];
  physicsObject->getRotationMatrix(rotMatrix);
  glMultMatrixf(rotMatrix);
  // glLoadMatrix(rotMatrix);
  //see ex01 -> WaveOBJ.cpp
  f16->display();
  glPopMatrix();
  delete rotMatrix;
}
