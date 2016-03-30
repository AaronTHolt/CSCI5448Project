#include "world.h"

#include <memory>

void World::registerGameObject(GameObject* go){
  spaceObjects.push_back(go);
  physicsWorld.registerGameObject(go);
}

World& World::getWorld(){
  static std::unique_ptr<World> theWorld(new World);
  return *theWorld;
}

void World::destroy(){
  static std::unique_ptr<World> theWorld;
  theWorld.reset(nullptr);
}

void World::draw() const{
  boundary.draw();
  for(const GameObject * const obj : spaceObjects){
    obj->draw();
  }
  //playerShip.draw();
}

World::~World(){
  for(GameObject* obj : spaceObjects){
    delete obj;
  }
}
