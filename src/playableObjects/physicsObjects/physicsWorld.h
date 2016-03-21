#ifndef _PHYSICS_WORLD_H_
#define _PHYSICS_WORLD_H_

#include "../gameObjects/gameObject.h"
#include "../gameObjects/shapes/GLDebugDrawer.h"

class PhysicsWorld{
 public:
  PhysicsWorld();
  ~PhysicsWorld();
  
  void registerGameObject(GameObject& obj);

 private:
  btCollisionConfiguration* collisionConfiguration;
  btCollisionDispatcher* collisionDispatcher;
  btBroadphaseInterface* pairCache;
  btConstraintSolver* solver;
  btCollisionWorld* world;

  btIDebugDraw* debugDrawer;
};

#endif
