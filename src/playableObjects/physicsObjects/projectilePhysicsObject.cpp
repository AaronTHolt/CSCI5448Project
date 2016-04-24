#include "projectilePhysicsObject.h"
#include "invalidOperationException.h"

ProjectilePhysicsObject::ProjectilePhysicsObject(const Vector3& pos,const Vector3& f, const Vector3& vel, GameObject* go){
  const float mass = 0.2;
  collisionShape = new btBoxShape(btVector3(0.1, 0.1, 0.1));
  // Add a pointer to the calling GameObject for collisions
  collisionShape->setUserPointer(go);
  btVector3 localInertia(0,0,0);
  collisionShape->calculateLocalInertia(mass, localInertia);
  rigidBody = createRigidBody(collisionShape, mass, pos, 0);
  rigidBody->setLinearVelocity(velocity*f+vel);
}

ProjectilePhysicsObject::~ProjectilePhysicsObject(){}

void ProjectilePhysicsObject::applyForce(){
  throw new InvalidOperationException();
}

void ProjectilePhysicsObject::applyRotationPitch(bool p){
  throw new InvalidOperationException();
}

void ProjectilePhysicsObject::applyRotationYaw(bool y){
  throw new InvalidOperationException();
}
