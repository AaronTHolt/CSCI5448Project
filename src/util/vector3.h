#ifndef _VECTOR_3_H_
#define _VECTOR_3_H_

#include "btBulletDynamicsCommon.h"

class Vector3{
 public:
  Vector3(); // creates a zero vector
  Vector3(float x, float y, float z);
  Vector3(const Vector3&);
  Vector3(const btVector3&);
  Vector3& operator=(const Vector3&);
  Vector3& operator=(const btVector3&);
 
  float getX() const;
  float getY() const;
  float getZ() const;

  // Conversion operator to btVector3
  //  Warning this is an implicit operator
  operator btVector3() const;

  // **********************************************
  // Mathematical Operation to be defined as needed
  // **********************************************

  // Scalar Multiplication
  Vector3 operator*(const float factor);
  Vector3 operator*=(const float factor);
  // Vector Addition
  Vector3 operator+(const Vector3& addend);
  Vector3 operator+=(const Vector3& addend);
  
 private:
  btVector3 vec;
};

#endif
