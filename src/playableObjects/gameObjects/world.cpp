#include "world.h"

World::World(){}

void World::registerGameObject(GameObject go){
  physicsWorld.registerGameObject(go);
}

static World World::getWorld(){
  if(nullptr == theWorld){
    theWorld = new World();
  }
  return *theWorld;
}

void World::draw() const{
  boundary.draw();
  for(GameObject& obj : spaceObjects){
    obj.draw();
  }
  playerShip.draw();
}
