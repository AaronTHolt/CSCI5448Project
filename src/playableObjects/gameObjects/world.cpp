#include "world.h"

World::World(){}

void World::registerGameObject(GameObject& go){
  spaceObjects.add(go);
  physicsWorld.registerGameObject(go);
}

static World& World::getWorld(){
  if(nullptr == theWorld){
    theWorld = new World();
  }
  return *theWorld;
}

static void World::destroy(){
  delete theWorld;
  theWorld = nullptr;
}

void World::draw() const{
  boundary.draw();
  for(GameObject& obj : spaceObjects){
    obj.draw();
  }
  playerShip.draw();
}
