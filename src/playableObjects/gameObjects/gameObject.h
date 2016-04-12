#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include "physicsObject.h"
#include "gameObjectType.h"

class GameObject{
 public:
  virtual ~GameObject();
  
  virtual void draw() const = 0;

  // This returns true if the object should collide and bounce
  //   as physics would normally dictate
  virtual bool onCollision(GameObjectType got);

  GameObjectType getType() const;
  PhysicsObject& getPhysicsObject();

 protected:
  PhysicsObject* physicsObject;
  GameObjectType type;

 protected:
  void warp(double maxToCenter);
  
};

#endif
