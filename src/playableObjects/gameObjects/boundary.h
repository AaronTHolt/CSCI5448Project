#ifndef _BOUNDARY_H_
#define _BOUNDARY_H_

#include "gameObject.h"
#include "cube.h"
#include "cubeSides.h"

class Boundary : public GameObject{
 public:
  Boundary(CubeSides side);
  ~Boundary();
  
  void draw() const;

  bool onCollision(GameObjectType got);
  double getDim();
 private:
  double x;
  double y;
  double z;
  const double dim = 50;
  // Cubes that make up the boundary
  Cube* bound;
  
};

#endif
