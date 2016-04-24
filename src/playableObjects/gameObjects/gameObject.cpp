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
      pos.setX(-boundaryEdge+1);
    }else{
      pos.setX(boundaryEdge-1);
    }
  }
  
  toBoundary = boundaryEdge - fabs(pos.getY());
  if(errorBounds > toBoundary){
    if(0 < pos.getY()){
      pos.setY(-boundaryEdge+1);
    }else{
      pos.setY(boundaryEdge-1);
    }
  }
  
  toBoundary = boundaryEdge - fabs(pos.getZ());
  if(errorBounds > toBoundary){
    if(0 < pos.getZ()){
      pos.setZ(-boundaryEdge+1);
    }else{
      pos.setZ(boundaryEdge-1);
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
