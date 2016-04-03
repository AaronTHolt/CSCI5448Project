#include "ship.h"
#include "objectLoader/waveOBJ.h"
#include <QString>
#include <QMessageBox>
#include <QDebug>

Ship::Ship() : GameObject()
{

    // F-16
    WaveOBJ* f16=0;
    try
    {
        f16 = new WaveOBJ("f-16.obj",":/");
    }
    catch (QString err)
    {
        qDebug() << err;
    }

    //Is this necessary/in the right place?
    if (f16)
    {
        f16->color(1,1,0);
        // objects.push_back(f16);
    }

    //add timer? see ex01 -> ex01opengl.cpp
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

//
//  Throw a fatal error and die
//
// void Ship::Fatal(QString message)
// {
//    QMessageBox::critical(this,"Ex01opengl",message);
//    QApplication::quit();
// }
