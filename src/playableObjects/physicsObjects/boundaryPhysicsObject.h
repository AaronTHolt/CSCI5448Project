#ifndef _BOUNDARY_PHYSICS_OBJECT_H_
#define _BOUNDARY_PHYSICS_OBJECT_H_

#include "physicsObject.h"
#include "vector3.h"

class BoundaryPhysicsObject: public PhysicsObject{
 public:
  // Contructor based on world half lengths
  BoundaryPhysicsObject(float x, float y, float z, const Vector3& pos, GameObject* go);
  ~BoundaryPhysicsObject();

  void applyForce();
  void applyRotationPitch(bool pitchUp);
  void applyRotationYaw(bool yawRight);
};

#endif
