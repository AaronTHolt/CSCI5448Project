#ifndef _BOUNDARY_H_
#define _BOUNDARY_H_

#include "gameObject.h"
#include "cube.h"
#include "cubeSides.h"

class Boundary : public GameObject{
 public:
  Boundary();
  ~Boundary();
  
  void draw() const;

 private:
  // Cubes that make up the boundary
  Cube* bounds[NUMSIDES];
  
};

#endif
