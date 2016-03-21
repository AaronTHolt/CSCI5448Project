#include "asteroid.h"

Asteroid::Asteroid(){
    // suzanne the monkey head asteroid
    WaveOBJ* suza=0;
    try
    {
        suza = new WaveOBJ("suzanne.obj",":/");
    }
    catch (QString err)
    {
        Fatal("Error loading object\n"+err);
    }

    //Is this necessary/in the right place?
    if (suza)
    {
        suza->color(1,1,0);
        objects.push_back(suza);
    }

    //add timer? see ex01 -> ex01opengl.cpp
}

void Asteroid::draw(){
    //see ex01 -> WaveOBJ.cpp
    suza->display();
}