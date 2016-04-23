#ifndef _WORLD_H_
#define _WORLD_H_

#include <vector>
#include <set>
#include <memory>

#include "gameObject.h"
#include "physicsWorld.h"
#include "boundary.h"
#include "ship.h"
#include "cubeSides.h"

class World{
 public:
  static std::weak_ptr<World> getWorld();
  static void destroy();
  ~World();

  World(const World&) = delete;
  void operator=(const World&) = delete;

  void registerGameObject(GameObject* go);
  void deregisterGameObject(GameObject* go);
  const std::vector<GameObject*> getGameObjects() const;
  void draw() const;
  void debugDraw(); // Not const because of bullet impl
  Ship* getPlayerShip();
  double getBoundaryDim() const;
  void stepWorld();
  void getPlayerShipTransform(float* matrix);
  const Vector3 getPlayerShipForward();
  
 private:
  Boundary* boundary[NUMSIDES];
  Ship playerShip;
  std::vector<GameObject*> spaceObjects;
  PhysicsWorld physicsWorld;

  // Private constuctors and Assignment
  World();

  // Getting rid of old game objects
  std::set<GameObject*> oldObjects;
  void clearOldObjects();

};

#endif
