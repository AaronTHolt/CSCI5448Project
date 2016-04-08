#include "world.h"

#include <memory>
#include <iostream>
#include <QGLWidget>

void World::registerGameObject(GameObject* go){
  spaceObjects.push_back(go);
  physicsWorld.registerGameObject(go);
}

std::weak_ptr<World> World::getWorld(){
  static std::shared_ptr<World> theWorld(new World);
  return std::weak_ptr<World>(theWorld);
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
  playerShip.draw();
}

void World::debugDraw(){
  physicsWorld.debugDraw();
}

void World::stepWorld(){
  physicsWorld.stepSim();
}

Ship* World::getPlayerShip(){
  return &playerShip;
}

World::World():boundary(),playerShip(){
  physicsWorld.registerGameObject(&boundary);
  physicsWorld.registerGameObject(&playerShip);
}

World::~World(){
  for(GameObject* obj : spaceObjects){
    delete obj;
  }
}
