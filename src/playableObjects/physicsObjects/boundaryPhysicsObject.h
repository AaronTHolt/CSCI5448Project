#ifndef _BOUNDARY_PHYSICS_OBJECT_H_
#define _BOUNDARY_PHYSICS_OBJECT_H_

#include "physicsObject.h"
#include "../cubeSides.h"


class BoundaryPhysicsObject: public PhysicsObject{
 public:
  // Contructor based on world half lengths
  BoundaryPhysicsObject(float x, float y, float z);
  ~BoundaryPhysicsObject();

  void applyForce();
  void applyRotationPitch(bool pitchUp);
  void applyRotationYaw(bool yawRight);

 private:
  btCollisionShape* subShapes[NUMSIDES];
};

#endif
