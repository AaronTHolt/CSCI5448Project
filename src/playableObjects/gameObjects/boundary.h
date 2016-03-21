#ifndef _BOUNDARY_H_
#define _BOUNDARY_H_

#include "gameObject.h"
#include "../cubeSides.h"

class Boundary : GameObject{
 public:
  Boundary();
  ~Boundary();
  
  void draw() const;

 private:
  // The physics Object for the boundary to the play area
  PhysicsObject* physicsObject;
  // Cubes that make up the boundary
  Cube* bounds[SIDES];

  
  
};

#endif
