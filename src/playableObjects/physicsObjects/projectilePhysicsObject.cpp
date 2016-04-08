#include "projectilePhysicsObject.h"
#include "invalidOperationException.h"

ProjectilePhysicsObject::ProjectilePhysicsObject(const Vector3& pos, const Vector3& vel){
  const float mass = 0.2;
  collisionShape = new btBoxShape(btVector3(0.1, 0.1, 0.1));
  btVector3 localInertia(0,0,0);
  collisionShape->calculateLocalInertia(mass, localInertia);
  rigidBody = createRigidBody(collisionShape, mass, pos, 0);
  rigidBody->setLinearVelocity(vel);
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
