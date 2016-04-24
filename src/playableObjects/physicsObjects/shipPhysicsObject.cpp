#include "shipPhysicsObject.h"

ShipPhysicsObject::ShipPhysicsObject(GameObject* go){
  // f-16 mass 12000 kg fully loaded
  const float mass = 2.0f;
  collisionShape = new btBoxShape(btVector3(1.0, 0.5, 1.5));
  // Add a pointer to the calling GameObject for collisions
  collisionShape->setUserPointer(go);
  btVector3 localInertia(0,0,0);
  collisionShape->calculateLocalInertia(mass, localInertia);
  rigidBody = createRigidBody(collisionShape, mass, btVector3(0,0,0), 0);
  rigidBody->setActivationState(DISABLE_DEACTIVATION);
}

ShipPhysicsObject::~ShipPhysicsObject(){}

void ShipPhysicsObject::applyForce(){
  btVector3 forward = getForward();
  forward *= force;
  rigidBody->applyCentralForce(forward);
}

void ShipPhysicsObject::applyRotationPitch(bool pitchUp){
  float delta = degreeToRadian(5);
  btQuaternion pitchChange = btQuaternion(0, delta*(pitchUp?1:-1), 0);
  btQuaternion newOrientation = rigidBody->getCenterOfMassTransform()*pitchChange;
  btTransform newTransform = rigidBody->getCenterOfMassTransform();
  newTransform.setRotation(newOrientation);
  rigidBody->setCenterOfMassTransform(newTransform);
}

void ShipPhysicsObject::applyRotationYaw(bool yawRight){
  float delta = degreeToRadian(5);
  btQuaternion yawChange = btQuaternion(delta*(yawRight?-1:1), 0, 0);
  btQuaternion newOrientation = rigidBody->getCenterOfMassTransform()*yawChange;
  btTransform newTransform = rigidBody->getCenterOfMassTransform();
  newTransform.setRotation(newOrientation);
  rigidBody->setCenterOfMassTransform(newTransform);
}

