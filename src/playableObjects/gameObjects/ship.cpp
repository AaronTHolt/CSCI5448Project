#include "ship.h"
#include "objectLoader/waveOBJ.h"
#include "shipPhysicsObject.h"
#include "basicWeapon.h"

#include <QString>
#include <QMessageBox>
#include <iostream>

Ship::Ship() : GameObject()
{
    basicWeapon = new BasicWeapon();
    type = GameObjectType::Ship;  
    physicsObject = new ShipPhysicsObject(this);


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
    const Vector3 tempPosition = physicsObject->getPosition();
    const Vector3 tempForward = physicsObject->getForward();
    const Vector3 tempVelocity = physicsObject->getVelocity();
    basicWeapon->fire(tempPosition,tempForward, tempVelocity);
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

const Vector3 Ship::getForward(){
  return physicsObject->getForward();
}

void Ship::getTransformMatrix(float* matrix){
  return physicsObject->getRotationMatrix(matrix);
}

bool Ship::onCollision(GameObjectType got){
  if(GameObjectType::Boundary == got){
    warp(4.0);
    return false;
  }
  // TODO: Needs to also take damage
  return true;
}
