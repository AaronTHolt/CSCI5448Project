#ifndef _WORLD_H_
#define _WORLD_H_

#include <vector>

#include "gameObject.h"
#include "physicsWorld.h"
#include "ship.h"

class World{
 public:
  void registerGameObject(GameObject go);
  static World getWorld();
  void draw() const;

 private:
  static World* theWorld = nullptr;
  Boundary boundary;
  Ship playerShip;
  std::vector<GameObject> spaceObjects;
  PhysicsWorld physicsWorld;
};

#endif
