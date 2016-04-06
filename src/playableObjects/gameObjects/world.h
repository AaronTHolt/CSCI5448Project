#ifndef _WORLD_H_
#define _WORLD_H_

#include <vector>
#include <memory>

#include "gameObject.h"
#include "physicsWorld.h"
#include "boundary.h"
#include "ship.h"

class World{
 public:
  void registerGameObject(GameObject* go);
  static std::weak_ptr<World> getWorld();
  static void destroy();
  void draw() const;
  void debugDraw();

  ~World();
  
  World(const World&) = delete;
  void operator=(const World&) = delete;

  Ship* getPlayerShip();
  void stepWorld();
  
 private:
  Boundary boundary;
  
  std::vector<GameObject*> spaceObjects;
  PhysicsWorld physicsWorld;

  // Private constuctors and Assignment
  World();

};

#endif
