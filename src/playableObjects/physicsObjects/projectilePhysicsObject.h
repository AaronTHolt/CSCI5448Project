#ifndef _PROJECTILE_PHYSICS_OBJECT_H_
#define _PROJECTILE_PHYSICS_OBJECT_H_

#include "physicsObject.h"


class ProjectilePhysicsObject : public PhysicsObject{
    public:
  ProjectilePhysicsObject(const Vector3& position, const Vector3& forward, const Vector3& velocity, GameObject* go);
        ~ProjectilePhysicsObject();

        void applyForce();
        void applyRotationPitch(bool pitchUp);
        void applyRotationYaw(bool yawRight);

 private:
	const unsigned int velocity = 10;
};

#endif
