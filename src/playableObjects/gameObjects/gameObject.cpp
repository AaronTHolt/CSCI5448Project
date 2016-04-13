#include "gameObject.h"
#include "world.h"

#include <cmath>

PhysicsObject& GameObject::getPhysicsObject(){
  return *physicsObject;
}

bool GameObject::onCollision(GameObjectType got){
  return true;
}

GameObjectType GameObject::getType() const{
  return type;
}

void GameObject::warp(double maxToCenter){
  double errorBounds = 0.1;
  double boundaryDim = World::getWorld().lock()->getBoundaryDim();
  double boundaryEdge = boundaryDim - maxToCenter;
  Vector3 pos = physicsObject->getPosition();

  double toBoundary = boundaryEdge - fabs(pos.getX());
  if(errorBounds > toBoundary){
    if(0 < pos.getX()){
      pos.setX(-boundaryEdge);
    }else{
      pos.setX(boundaryEdge);
    }
  }
  
  toBoundary = boundaryEdge - fabs(pos.getY());
  if(errorBounds > toBoundary){
    if(0 < pos.getY()){
      pos.setY(-boundaryEdge);
    }else{
      pos.setY(boundaryEdge);
    }
  }
  
  toBoundary = boundaryEdge - fabs(pos.getZ());
  if(errorBounds > toBoundary){
    if(0 < pos.getZ()){
      pos.setZ(-boundaryEdge);
    }else{
      pos.setZ(boundaryEdge);
    }
  }

  // Now move the object
  physicsObject->setPosition(pos);
}

// Need Definition for destructor
//  Deletes Physics Object
GameObject::~GameObject(){
  delete physicsObject;
}
