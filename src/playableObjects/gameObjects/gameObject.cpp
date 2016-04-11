#include "gameObject.h"

PhysicsObject& GameObject::getPhysicsObject(){
  return *physicsObject;
}

bool GameObject::onCollision(GameObjectType got){
  return true;
}

GameObjectType GameObject::getType() const{
  return type;
}

// Need Definition for destructor
//  Deletes Physics Object
GameObject::~GameObject(){
  delete physicsObject;
}
