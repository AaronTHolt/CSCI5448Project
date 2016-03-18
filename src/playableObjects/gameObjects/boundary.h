#ifndef _BOUNDARY_H_
#define _BOUNDARY_H_

class Boundary : GameObject{
 public:
  Boundary();
  ~Boundary();
  
  void draw() const;

 private:
  // The physics Object for the boundary to the play area
  PhysicsObject* physicsObject;
  // Half lengths of the dimensions of the play area
  double x;
  double y;
  double z;
  
};

#endif
