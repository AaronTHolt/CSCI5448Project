#ifndef _PROJECTILE_PHYSICS_OBJECT_H_
#define _PROJECTILE_PHYSICS_OBJECT_H_

#include "physicsObject.h"

class ProjectilePhysicsObject : public PhysicsObject{
    public:
        ProjectilePhysicsObject(const Vector3& position, const Vector3& velocity);
        ~ProjectilePhysicsObject();

        void applyForce();
        void applyRotationPitch(bool pitchUp);
        void applyRotationYaw(bool yawRight);
  
};

#endif
