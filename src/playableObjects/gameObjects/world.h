#ifndef _WORLD_H_
#define _WORLD_H_

#include <vector>

#include "gameObject.h"
#include "physicsWorld.h"
#include "boundary.h"
//#include "ship.h"

class World{
 public:
  void registerGameObject(GameObject* go);
  static World& getWorld();
  static void destroy();
  void draw() const;

  ~World();
  
  World(const World&) = delete;
  void operator=(const World&) = delete;
  
  
 private:
  Boundary boundary;
  //Ship playerShip;
  std::vector<GameObject*> spaceObjects;
  PhysicsWorld physicsWorld;

  // Private constuctors and Assignment
  World(){};
    
};

#endif
