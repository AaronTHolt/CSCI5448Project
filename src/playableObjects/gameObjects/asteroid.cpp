#include "asteroid.h"
#include "world.h"


Asteroid::Asteroid(Vector3 p, AsteroidSize size) : GameObject()
{
    double radius = 0.0;
    asteroidSize = size;
    switch(asteroidSize){
        case AsteroidSize::Small:
            radius = 0.5;
            break;
        case AsteroidSize::Medium:
            radius = 1.0;
            break;
        case AsteroidSize::Large:
            radius = 1.5;
            break;
    }

    physicsObject = new AsteroidPhysicsObject(radius, p, this);
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
  switch(got){
  case GameObjectType::Boundary:
    warp(2.0);
    return false;
  case GameObjectType::Asteroid:
    return true;
  default:
    split();
    World::getWorld().lock()->deregisterGameObject(this);
    return false;
  }
}

void Asteroid::split(){

    std::weak_ptr<World> theWorld;
    theWorld = World::getWorld();

    Vector3 position = physicsObject->getPosition();
    switch(asteroidSize){
        case AsteroidSize::Large:
            theWorld.lock()->registerGameObject( new Asteroid(position+Vector3(1,0,0), AsteroidSize::Medium) );
            theWorld.lock()->registerGameObject( new Asteroid(position+Vector3(0,1,0), AsteroidSize::Medium) );
            theWorld.lock()->registerGameObject( new Asteroid(position+Vector3(0,0,1), AsteroidSize::Medium) );
            break;
        case AsteroidSize::Medium:
            theWorld.lock()->registerGameObject( new Asteroid(position+Vector3(1,0,0), AsteroidSize::Small) );
            theWorld.lock()->registerGameObject( new Asteroid(position+Vector3(0,1,0), AsteroidSize::Small) );
            theWorld.lock()->registerGameObject( new Asteroid(position+Vector3(0,0,1), AsteroidSize::Small) );
            break;
        case AsteroidSize::Small:
            break;
    }
}


