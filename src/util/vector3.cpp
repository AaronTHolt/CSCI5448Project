#include "vector3.h"

Vector3::Vector3(){
  vec = btVector3(0.0, 0.0, 0.0);
}

Vector3::Vector3(float x, float y, float z){
  vec = btVector3(x,y,z);
}

Vector3::Vector3(const Vector3& other){
  vec = other.vec;
}

Vector3::Vector3(const btVector3& other){
  vec = other;
}

Vector3& Vector3::operator=(const Vector3& other){
  vec = other.vec;
  return *this;
}

Vector3& Vector3::operator=(const btVector3& other){
  vec = other;
  return *this;
}

float Vector3::getX() const{
  return vec.x();
}

float Vector3::getY() const{
  return vec.y();
}

float Vector3::getZ() const{
  return vec.z();
}

Vector3::operator btVector3() const{
  return vec;
}


Vector3 Vector3::operator*(const float factor){
  return vec * factor;
}

Vector3 Vector3::operator*=(const float factor){
  vec *= factor;
  return *this;
}

Vector3 Vector3::operator+(const Vector3& addend){
  return vec + addend;
}

Vector3 Vector3::operator+=(const Vector3& addend){
  vec += addend;
  return *this;
}
