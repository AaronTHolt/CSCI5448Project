#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include "physicsObject.h"

class GameObject{
 public:
  virtual ~GameObject() = 0;
  
  virtual void draw() const = 0;

  PhysicsObject& getPhysicsObject();

 protected:
  PhysicsObject* physicsObject;
  
};

#endif
