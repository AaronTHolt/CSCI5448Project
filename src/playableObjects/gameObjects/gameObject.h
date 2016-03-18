#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

class GameObject{
 public:
  virtual GameObject() = 0;
  virtual ~GameObject() = 0;
  
  virtual void draw() const = 0;

 private:
  PhysicsObject* physicsObject;
  
};

#endif
