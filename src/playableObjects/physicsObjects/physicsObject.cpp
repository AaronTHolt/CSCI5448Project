#include "physicsObject.h"

#include <cmath>

btRigidBody* PhysicsObject::getRigidBody(){
  return rigidBody;
}

btRigidBody* PhysicsObject::createRigidBody(btCollisionShape* shape, float mass, btVector3 pos, double ry){
  btVector3 localInertia(0,0,0);
  btTransform transform;
  transform.setIdentity();
  transform.setOrigin(pos);
  btQuaternion rot(btVector3(0,1,0), ry*PI/180.0);
  transform.setRotation(rot);
  motionState = new btDefaultMotionState(transform);
  btRigidBody::btRigidBodyConstructionInfo rbInfo(mass,motionState,shape,localInertia);
  return new btRigidBody(rbInfo);
}

float PhysicsObject::degreeToRadian(float degree){
  return degree * M_PI / 180.0;
}

float PhysicsObject::radianToDegree(float radian){
  return radian * 180.0 / M_PI;
}

// PhysicsObject Destructor
//  This deletes the rigid body and collisionShape
PhysicsObject::~PhysicsObject(){
  delete rigidBody;
  delete collisionShape;
  delete motionState;
}

void PhysicsObject::getRotationMatrix(float * mat){
  const int matDim = 16;
  for(int i = 0; i < matDim; i++){
    mat[i] = 0;
  }
  rigidBody->getCenterOfMassTransform().getOpenGLMatrix(mat);
}
