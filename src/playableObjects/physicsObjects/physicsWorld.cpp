#include "physicsWorld.h"
#include "world.h"

#include <algorithm>
#include <iostream>


PhysicsWorld::PhysicsWorld(){
  // collision configuration contains default setup for memory, collision setup. Advanced users can create their own configuration.
  collisionConfiguration = new btDefaultCollisionConfiguration();
  // use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded)
  collisionDispatcher = new btCollisionDispatcher(collisionConfiguration);
  // Add a custom neadCallback
  collisionDispatcher->setNearCallback(nearCallback);
  
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

// Near Callback for the physics where interactions can be specified
void PhysicsWorld::nearCallback(btBroadphasePair& collisionPair,
				btCollisionDispatcher& dispatcher,
				const btDispatcherInfo& dispatcherInfo){

  // This m_pProxy*->m_clientObject is the rigid body for of the colliding object
  //   I artificially gave the collisionshapes UserPointers to their GameObjects
  GameObject* obj1 = (GameObject*)((btRigidBody*)collisionPair.m_pProxy0->m_clientObject)->getCollisionShape()->getUserPointer();
  GameObject* obj2 = (GameObject*)((btRigidBody*)collisionPair.m_pProxy1->m_clientObject)->getCollisionShape()->getUserPointer();

  bool nonNullObjects = nullptr != obj1 && nullptr != obj2;
  bool obj1DoesNormal = true;
  bool obj2DoesNormal = true;
  if(nonNullObjects){
    obj1DoesNormal = obj1->onCollision(obj2->getType());
    obj2DoesNormal = obj2->onCollision(obj1->getType());
    std::cout << "Both objects here." << std::endl;
  } else{
    std::cout << "There is a null object." << std::endl;
  }
  
  if(nonNullObjects || (obj1DoesNormal && obj2DoesNormal)){
    // Do the normal Near Callback
    dispatcher.defaultNearCallback(collisionPair, dispatcher, dispatcherInfo);
  }
}
