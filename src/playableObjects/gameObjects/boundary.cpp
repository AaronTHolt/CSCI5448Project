#include "boundary.h"

Boundary::Boundary(){
  // Half lengths of the dimensions of the play area
  x = 1000.0;
  y = 1000.0;
  z = 1000.0;
  // Construct the physics object for the boundary to the play area
  physicsObject = new BoundaryPhysicsObject(x,y,z);
}

Boundary::~Boundary(){
  delete physicsObject;
}

void Boundary::draw() const{
  //Draw cubes at the bounding areas
  //TODO: draw the boundry cubes
  //TODO: add the image texture to the cubes
}
