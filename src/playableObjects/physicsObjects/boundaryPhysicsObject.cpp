#include "boundaryPhysicsObject.h"

#include "invalidOperationException.h"

#include "btBulletDynamicsCommon.h"
#include "LinearMath/btTransform.h"

BoundaryPhysicsObject::BoundaryPhysicsObject(float x, float y, float z){
  // Create the compound shape which represents the whole boundary
  btCompoundShape* compoundShape = new btCompoundShape();
  // Create the subshapes that are each side that comprise the whole boundary
  subShapes[+CubeSides::Top] = new btBoxShape(btVector3(1.0, y, z));
  subShapes[+CubeSides::Bottom] = new btBoxShape(btVector3(1.0, y, z));
  subShapes[+CubeSides::Left] = new btBoxShape(btVector3(x, 1.0, z));
  subShapes[+CubeSides::Right] = new btBoxShape(btVector3(x, 1.0, z));
  subShapes[+CubeSides::Front] = new btBoxShape(btVector3(x, y, 1.0));
  subShapes[+CubeSides::Back] = new btBoxShape(btVector3(x, y, 1.0));

  // Attach each subShape to the whole boundary
  btTransform transform; // The transformation to where each shape goes in space
  // Top
  transform.setOrigin(btVector3(0,y,0));
  compoundShape->addChildShape(transform, subShapes[+CubeSides::Top]);
  // Bottom
  transform.setOrigin(btVector3(0,-y,0));
  compoundShape->addChildShape(transform, subShapes[+CubeSides::Bottom]);
  // Left
  transform.setOrigin(btVector3(-x,0,0));
  compoundShape->addChildShape(transform, subShapes[+CubeSides::Left]);
  // Right
  transform.setOrigin(btVector3(x,0,0));
  compoundShape->addChildShape(transform, subShapes[+CubeSides::Right]);
  // Front
  transform.setOrigin(btVector3(0,0,z));
  compoundShape->addChildShape(transform, subShapes[+CubeSides::Front]);
  // Back
  transform.setOrigin(btVector3(0,0,-z));
  compoundShape->addChildShape(transform, subShapes[+CubeSides::Back]);

  collisionShape = compoundShape;
  rigidBody = createRigidBody(collisionShape, 0.0f, btVector3(0,0,0), 0);
}

BoundaryPhysicsObject::~BoundaryPhysicsObject(){
  // Rigid Body and Collision Shape are deleted by PhysicsObject

  // Delete each of the sub shapes
  delete subShapes[+CubeSides::Top];
  delete subShapes[+CubeSides::Bottom];
  delete subShapes[+CubeSides::Left];
  delete subShapes[+CubeSides::Right];
  delete subShapes[+CubeSides::Front];
  delete subShapes[+CubeSides::Back];
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
