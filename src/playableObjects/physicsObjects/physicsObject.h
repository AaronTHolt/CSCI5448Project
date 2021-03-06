#ifndef _PHYSICS_OBJECT_H_
#define _PHYSICS_OBJECT_H_

#include "vector3.h"

#include "btBulletDynamicsCommon.h"

#define PI 3.14159265

// Tell a physics object that there is such a thing as a GameObject
class GameObject;

class PhysicsObject{
 public:
  virtual ~PhysicsObject() = 0;
  virtual void applyForce() = 0;
  virtual void applyRotationPitch(bool pitchUp) = 0;
  virtual void applyRotationYaw(bool yawRight) = 0;
  
  void getRotationMatrix(float* mat);
  const Vector3 getForward() const;
  const Vector3 getPosition() const;
  const Vector3 getVelocity() const;
  const Vector3 getUp() const;
  btRigidBody* getRigidBody();

  void setPosition(Vector3& vec);
  
 protected:
  btCollisionShape* collisionShape;
  btRigidBody* rigidBody;

 protected:
  btRigidBody* createRigidBody(btCollisionShape* shape,
			       float mass, btVector3 pos,
			       double ry);
  float degreeToRadian(float degree);
  float radianToDegree(float radian);

 private:
  btMotionState* motionState;
};

#endif
