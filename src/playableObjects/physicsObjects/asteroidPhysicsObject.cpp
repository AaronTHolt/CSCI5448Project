#include "asteroidPhysicsObject.h"

#include <chrono>

AsteroidPhysicsObject::AsteroidPhysicsObject(float r, const Vector3& pos, GameObject* go){
  // Create Random Number Generator
  // obtain a seed from the system clock:
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  generator = std::mt19937(seed);

  // Create necessary things for physics objects
  const float mass = 20.f;
  collisionShape = new btSphereShape(r);
  // Add a pointer to the calling GameObject for collisions
  collisionShape->setUserPointer(go);
  // Calculates an objects inertia
  btVector3 localInertia(0,0,0);
  collisionShape->calculateLocalInertia(mass, localInertia);
  rigidBody = createRigidBody(collisionShape, mass, pos, 0);
  rigidBody->setLinearVelocity(force*getRandomVector());
  rigidBody->setAngularVelocity(force*getRandomVector());
}

AsteroidPhysicsObject::~AsteroidPhysicsObject(){}

btVector3 AsteroidPhysicsObject::getRandomVector(){
  int x = generator();
  int y = generator();
  int z = generator();
  int halfMax = generator.max()/2;
  // make so that can be negatives
  x -= halfMax;
  y -= halfMax;
  z -= halfMax;
  btVector3 vec(x,y,z);
  return vec.normalize();
}

void AsteroidPhysicsObject::applyForce(){
  rigidBody->applyCentralForce(force*getRandomVector());
}

void AsteroidPhysicsObject::applyRotationPitch(bool pitchUp){
  rigidBody->applyTorque(force*getRandomVector());
}

void AsteroidPhysicsObject::applyRotationYaw(bool yawRight){
  rigidBody->applyTorque(force*getRandomVector());
}
