#ifndef _PHYSICS_OBJECT_H_
#define _PHYSICS_OBJECT_H_

class PhysicsObject{
 public:
  virtual ~PhysicsObject() = 0;
  virtual void applyForce() = 0;
  virtual void applyRotationPitch(bool pitchUp) = 0;
  virtual void applyRotationPitch(bool yawRight) = 0;

 private:
  btCollisionShape* collisionShape;
  btRigidBody* rigidBody;

 protected:
  btRigidBody* createRigidBody(btCollisionShape* shape,
			       float mass, btVector3 pos,
			       double ry)
};

#endif
