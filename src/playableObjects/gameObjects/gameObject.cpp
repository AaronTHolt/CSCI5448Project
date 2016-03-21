#include gameObject.h

PhysicsObject& GameObject::getPhysicsObject(){
  return *physicsObject;
}
