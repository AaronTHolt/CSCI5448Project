#include "asteroid.h"


Asteroid::Asteroid(Vector3 p) : GameObject()
{

    physicsObject = new AsteroidPhysicsObject(1.5, p);
    type = GameObjectType::Asteroid;
    // suzanne the monkey head asteroid
    asteroid=0;
    try
    {
        asteroid = new WaveOBJ("suzanne.obj",":/");
    }
    catch (QString err)
    {
        // Fatal("Error loading object\n"+err);
        // QMessageBox::critical(this,"Ship",err);
        // QApplication::quit();
    }

    //Is this necessary/in the right place?
    if (asteroid)
    {
        asteroid->color(0,1,1);
    }
}

Asteroid::~Asteroid(){
    delete asteroid;
}

void Asteroid::draw() const{
    glPushMatrix();
    float* rotMatrix = new float[16];
    physicsObject->getRotationMatrix(rotMatrix);
    glMultMatrixf(rotMatrix);
    asteroid->display();
    glPopMatrix();
    delete rotMatrix;
}

bool Asteroid::onCollision(GameObjectType got){
  if(GameObjectType::Asteroid == got){
    return true;
  }

  return false;

}
