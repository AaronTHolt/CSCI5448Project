#include "asteroid.h"
#include "objectLoader/waveOBJ.h"
#include <QString>
#include <QMessageBox>
#include <QDebug>

Asteroid::Asteroid(){
    // suzanne the monkey head asteroid
    WaveOBJ* asteroid = 0;
    try
    {
        asteroid = new WaveOBJ("suzanne.obj",":/");
    }
    catch (QString err)
    {
        qDebug() << err;
    }

    //Is this necessary/in the right place?
    if (asteroid)
    {
        asteroid->color(1,1,0);
    }
}

Asteroid::~Asteroid()
{
    delete asteroid;
}

void Asteroid::draw() const{
    //see ex01 -> WaveOBJ.cpp
    asteroid->display();
}