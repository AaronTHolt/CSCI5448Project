#ifndef _SHIP_PHYSICS_OBJECT_H_
#define _SHIP_PHYSICS_OBJECT_H_

#include "physicsObject.h"
#include "vector3.h"

class ShipPhysicsObject : public PhysicsObject{
 public:
  ShipPhysicsObject();
  ~ShipPhysicsObject();

  void applyForce();
  void applyRotationPitch(bool pitchUp);
  void applyRotationYaw(bool yawRight);
  const Vector3 getForward() const;

 private:
  const unsigned int force = 5; // m/s^2
  
};

#endif
