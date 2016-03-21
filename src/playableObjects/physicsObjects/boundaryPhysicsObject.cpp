#include "boundaryPhysicsObject.h"
#include "invalidOperationException.h"

BoundaryPhysicsObject::BoundaryPhysicsObject(float x, float y, float z){
  // Create the compound shape which represents the whole boundary
  collisionShape = new btCompoundShape();
  // Create the subshapes that are each side that comprise the whole boundary
  subShapes[Top] = new btBoxShape(1.0, y, z);
  subShapes[Bottom] = new btBoxShpae(1.0, y, z);
  subShapes[Left] = new btBoxShape(x, 1.0, z);
  subShapes[Right] = new btBoxShape(x, 1.0, z);
  subShapes[Front] = new btBoxShape(x, y, 1.0);
  subShapes[Back] = new btBoxShape(x, y, 1.0);

  // Attach each subShape to the whole boundary
  btTransform transform(); // The transformation to where each shape goes in space
  // Top
  transform.setOrigin(btVector3(0,y,0));
  collisionShape->addChildShape(transform, subShape(Top));
  // Bottom
  transform.setOrigin(btVector3(0,-y,0));
  collisionShape->addChildShape(transform, subShape(Bottom));
  // Left
  transform.setOrigin(btVector3(-x,0,0));
  collisionShape->addChildShape(transform, subShape(Left));
  // Right
  transform.setOrigin(btVector3(x,0,0));
  collisionShape->addChildShape(transform, subShape(Right));
  // Front
  transform.setOrigin(btVector3(0,0,z));
  collisionShape->addChildShape(transform, subShape(Front));
  // Back
  transform.setOrigin(btVector3(0,0,-z));
  collisionShape->addChildShape(transform, subShape(Back));

  rigidBody = createRigidBody(collisionShape, 0.0f, btVector3(0,0,0), 0);
}

BoundaryPhysicsObject::~BoundaryPhysicsObject(){
  // Delete each of the sub shapes
  delete subShapes[Top];
  delete subShapes[Bottom];
  delete subShapes[Left];
  delete subShapes[Right];
  delete subShapes[Front];
  delete subShapes[Back];

  // Delete the compound Shape
  delete collisionShape;

  // Delete the rigid body
  delete rigidBody;
}

BoundaryPhysicsObject::applyForce(){
  throw new InvalidOperationException();
}

BoundaryPhysicsObject::applyRotationPitch(bool isPitchUp){
  throw new InvalidOperationException();
}

BoundaryPhysicsObject::applyRotationYaw(bool isYawRight){
  throw new InvalidOperationException();
}
