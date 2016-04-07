 #ifndef _PHYSICS_OBJECT_H_
#define _PHYSICS_OBJECT_H_

#include "btBulletDynamicsCommon.h"

#define PI 3.14159265

class PhysicsObject{
 public:
  virtual ~PhysicsObject() = 0;
  virtual void applyForce() = 0;
  virtual void applyRotationPitch(bool pitchUp) = 0;
  virtual void applyRotationYaw(bool yawRight) = 0;
  
  void getRotationMatrix(float* mat);
  btRigidBody* getRigidBody();
  
 protected:
  btCollisionShape* collisionShape;
  btRigidBody* rigidBody;

 protected:
  btRigidBody* createRigidBody(btCollisionShape* shape,
			       float mass, btVector3 pos,
			       double ry);
  float degreeToRadian(float degree);
  float radianToDegree(float radian);
};

#endif
