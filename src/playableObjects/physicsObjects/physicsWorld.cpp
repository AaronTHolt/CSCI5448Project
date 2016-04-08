#include "physicsWorld.h"

PhysicsWorld::PhysicsWorld(){
  // collision configuration contains default setup for memory, collision setup. Advanced users can create their own configuration.
  collisionConfiguration = new btDefaultCollisionConfiguration();
  // use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded)
  collisionDispatcher = new btCollisionDispatcher(collisionConfiguration);
  // btDbvtBroadphase is a good general purpose broadphase.
  pairCache = new btDbvtBroadphase();
  // the default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded)
  solver = new btSequentialImpulseConstraintSolver();
  
  world = new btDiscreteDynamicsWorld(collisionDispatcher,pairCache,solver,collisionConfiguration);

  // Set the Debug Drawer if not set already
  if(NULL == world->getDebugDrawer()){
    debugDrawer = new GLDebugDrawer();
    world->setDebugDrawer(debugDrawer);
  }
  // There is no gravity
  world->setGravity(btVector3(0,0,0));
  // Set the Debug Drawer State
  world->getDebugDrawer()->setDebugMode(btIDebugDraw::DBG_DrawWireframe);
  
}

void PhysicsWorld::stepSim(){
  world->stepSimulation(1.f/60.f, 10);
}

void PhysicsWorld::debugDraw(){
  world->debugDrawWorld();
}

PhysicsWorld::~PhysicsWorld(){
  delete world;
  delete solver;
  delete pairCache;
  delete collisionDispatcher;
  delete collisionConfiguration;
  delete debugDrawer;
}

void PhysicsWorld::registerGameObject(GameObject* obj){
  world->addRigidBody(obj->getPhysicsObject().getRigidBody());
}
