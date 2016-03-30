#include "gameObject.h"

PhysicsObject& GameObject::getPhysicsObject(){
  return *physicsObject;
}

// Need Definition for destructor
//  Deletes Physics Object
GameObject::~GameObject(){
  delete physicsObject;
}
