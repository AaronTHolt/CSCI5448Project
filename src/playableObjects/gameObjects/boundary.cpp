#include "boundary.h"
#include "../cubeSides.h"

Boundary::Boundary(){
  // Half lengths of the dimensions of the play area
  x = 500.0;
  y = 500.0;
  z = 500.0;  
  // Construct the physics object for the boundary to the play area
  physicsObject = new BoundaryPhysicsObject(x,y,z);

  // Construct the Boundary objects for drawing
  bounds[Top] = new Cube(0,y,0, x,1,z, 0);
  bounds[Bottom] = new Cube(0,-y,0, x,1,z, 0);
  bounds[Left] = new Cube(-x,0,0, 1,y,z, 0);
  bounds[Right] = new Cube(x,0,0, 1,y,z, 0);
  bounds[Front] = new Cube(0,0,z, x,y,1, 0);
  bounds[Back] = new Cube(0,0,-z, x,y,1, 0);
}

Boundary::~Boundary(){
  // Delete the bounds physics object
  delete physicsObject;

  // Delete the bounds Cube objects
  delete bounds[Top];
  delete bounds[Bottom];
  delete bounds[Left];
  delete bounds[Right];
  delete bounds[Front];
  delete bounds[Back];
}

void Boundary::draw() const{
  //Draw cubes at the bounding areas
  //TODO: add the image texture to the cubes

  // Store Transform Matrix
  glPushMatrix();

  // Draw the bounds
  bounds[Top].draw();
  bounds[Bottom].draw();
  bounds[Left].draw();
  bounds[Right].draw();
  bounds[Front].draw();
  bounds[Back].draw();

  // Restore Transform Matrix
  glPopMatrix();
}
