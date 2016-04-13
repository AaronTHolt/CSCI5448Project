#ifndef _PHYSICS_WORLD_H_
#define _PHYSICS_WORLD_H_

#include <vector>

#include "../gameObjects/gameObject.h"
#include "../gameObjects/shapes/GLDebugDrawer.h"

class PhysicsWorld{
 public:
  PhysicsWorld();
  ~PhysicsWorld();
  
  void registerGameObject(GameObject* obj);
  void deregisterGameObject(GameObject* obj);
  void stepSim();

  void debugDraw();

 private:
  btCollisionConfiguration* collisionConfiguration;
  btCollisionDispatcher* collisionDispatcher;
  btBroadphaseInterface* pairCache;
  btConstraintSolver* solver;
  btDynamicsWorld* world;

  btIDebugDraw* debugDrawer;

  // ******************************************
  // Near Callback and Object Interaction Rules
  // ******************************************
 private:
  static void nearCallback(btBroadphasePair& collisionPair,
		    btCollisionDispatcher& dispatcher,
		    const btDispatcherInfo& dispatcherInfo);
};

#endif
