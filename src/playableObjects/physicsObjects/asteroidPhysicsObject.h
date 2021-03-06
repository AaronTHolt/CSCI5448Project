#ifndef _ASTEROID_PHYSICS_OBJECT_H_
#define _ASTEROID_PHYSICS_OBJECT_H_

#include "physicsObject.h"

#include <random>

class AsteroidPhysicsObject : public PhysicsObject{
 public:
  AsteroidPhysicsObject(float radius, const Vector3& position, GameObject* go);
  ~AsteroidPhysicsObject();

  void applyForce();
  void applyRotationPitch(bool pitchUp);
  void applyRotationYaw(bool yawRight);

 private:
  const unsigned int force = 5;
  btVector3 getRandomVector();

  std::mt19937 generator;
  
};

#endif
