#include "world.h"

World::World(){
  theWorld = this;
}

void World::registerGameObject(GameObject go){
  physicsWorld.registerGameObject(go);
}

static World World::getWorld(){
  return *this;
}

void World::draw() const{
  boundary.draw();
  for(GameObject& obj : spaceObjects){
    obj.draw();
  }
  playerShip.draw();
}
