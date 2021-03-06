#include "world.h"
#include "asteroid.h"
#include "gameObjectType.h"

#include <memory>
#include <iostream>
#include <algorithm>
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
  for(int i = 0; i < NUMSIDES; i++){
    boundary[i]->draw();
  }
  for(const GameObject * const obj : spaceObjects){
    obj->draw();
  }
  playerShip.draw();

  // GL Debugging
  //std::cout << glGetError() << std::endl;
}

void World::debugDraw(){
  physicsWorld.debugDraw();
}

void World::stepWorld(){
  physicsWorld.stepSim();
  clearOldObjects();
}

Ship* World::getPlayerShip(){
  return &playerShip;
}

void World::getPlayerShipTransform(float* matrix){
  playerShip.getTransformMatrix(matrix);
}

const Vector3 World::getPlayerShipForward(){
  return playerShip.getForward();
}

double World::getBoundaryDim() const{
  return boundary[0]->getDim();
}

void World::deregisterGameObject(GameObject* go){
  oldObjects.insert(go);
}

void World::clearOldObjects(){
  for(GameObject* go : oldObjects){
    spaceObjects.erase(std::remove(spaceObjects.begin(),
				   spaceObjects.end(),
				   go),
		       spaceObjects.end()
		       );
    physicsWorld.deregisterGameObject(go);
    delete go;
  }
  oldObjects.clear();
}

const std::vector<GameObject*> World::getGameObjects() const{
  return spaceObjects;
}

World::World():playerShip(){
  boundary[+CubeSides::Top] = new Boundary(CubeSides::Top);
  boundary[+CubeSides::Bottom] = new Boundary(CubeSides::Bottom);
  boundary[+CubeSides::Left] = new Boundary(CubeSides::Left);
  boundary[+CubeSides::Right] = new Boundary(CubeSides::Right);
  boundary[+CubeSides::Front] = new Boundary(CubeSides::Front);
  boundary[+CubeSides::Back] = new Boundary(CubeSides::Back);
  for(int i = 0; i < NUMSIDES; i++){
    physicsWorld.registerGameObject(boundary[i]);
  }

  physicsWorld.registerGameObject(&playerShip);
  
  this->registerGameObject(new Asteroid(Vector3(20,20,20)));
  this->registerGameObject(new Asteroid(Vector3(35,-20,1)));
  this->registerGameObject(new Asteroid(Vector3(-20,-20,-20)));


}

World::~World(){
  for(int i = 0; i < NUMSIDES; i++){
    delete boundary[i];
  }
  
  for(GameObject* obj : spaceObjects){
    delete obj;
  }
}
