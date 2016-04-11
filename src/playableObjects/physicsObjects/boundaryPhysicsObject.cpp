#include "boundaryPhysicsObject.h"

#include "invalidOperationException.h"

#include "btBulletDynamicsCommon.h"
#include "LinearMath/btTransform.h"

BoundaryPhysicsObject::BoundaryPhysicsObject(float x, float y, float z, const Vector3& pos, GameObject* go){
  collisionShape = new btBoxShape(btVector3(x,y,z));
  collisionShape->setUserPointer(go);
  rigidBody = createRigidBody(collisionShape, 0.0f, pos, 0);
}

BoundaryPhysicsObject::~BoundaryPhysicsObject(){
  // Rigid Body and Collision Shape are deleted by PhysicsObject
}

void BoundaryPhysicsObject::applyForce(){
  throw new InvalidOperationException();
}

void BoundaryPhysicsObject::applyRotationPitch(bool isPitchUp){
  throw new InvalidOperationException();
}

void BoundaryPhysicsObject::applyRotationYaw(bool isYawRight){
  throw new InvalidOperationException();
}
