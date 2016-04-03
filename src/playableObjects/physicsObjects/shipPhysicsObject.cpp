#include "shipPhysicsObject.h"

ShipPhysicsObject::ShipPhysicsObject(){
  collisionShape = new btBoxShape(btVector3(2.0, 1.0, 2.0));
  // f-16 mass 12000 kg fully loaded
  rigidBody = createRigidBody(collisionShape, 12.0f, btVector3(0,0,0), 0);
}

ShipPhysicsObject::~ShipPhysicsObject(){}

void ShipPhysicsObject::applyForce(){
  btTransform front = rigidBody->getCenterOfMassTransform();
  btVector3 forward = btVector3(1,0,0);
  forward = front(forward);
  forward*=force;
  rigidBody->applyCentralForce(forward);
}

void ShipPhysicsObject::applyRotationPitch(bool pitchUp){
  float delta = degreeToRadian(10);
  btQuaternion pitchChange = btQuaternion(0, delta*(pitchUp?1:-1), 0);
  btQuaternion newOrientation = rigidBody->getCenterOfMassTransform()*pitchChange;
  btTransform newTransform = rigidBody->getCenterOfMassTransform();
  newTransform.setRotation(newOrientation);
  rigidBody->setCenterOfMassTransform(newTransform);
}

void ShipPhysicsObject::applyRotationYaw(bool pitchUp){
  float delta = degreeToRadian(10);
  btQuaternion yawChange = btQuaternion(0, 0, delta*(pitchUp?1:-1));
  btQuaternion newOrientation = rigidBody->getCenterOfMassTransform()*yawChange;
  btTransform newTransform = rigidBody->getCenterOfMassTransform();
  newTransform.setRotation(newOrientation);
  rigidBody->setCenterOfMassTransform(newTransform);
}
