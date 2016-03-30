#include "boundary.h"

#include "boundaryPhysicsObject.h"

#include <QGLWidget>

Boundary::Boundary(){
  // Half lengths of the dimensions of the play area
  double x = 500.0;
  double y = 500.0;
  double z = 500.0;  
  // Construct the physics object for the boundary to the play area
  physicsObject = new BoundaryPhysicsObject(x,y,z);

  // Construct the Boundary objects for drawing
  bounds[+CubeSides::Top] = new Cube(0,y,0, x,1,z, 0);
  bounds[+CubeSides::Bottom] = new Cube(0,-y,0, x,1,z, 0);
  bounds[+CubeSides::Left] = new Cube(-x,0,0, 1,y,z, 0);
  bounds[+CubeSides::Right] = new Cube(x,0,0, 1,y,z, 0);
  bounds[+CubeSides::Front] = new Cube(0,0,z, x,y,1, 0);
  bounds[+CubeSides::Back] = new Cube(0,0,-z, x,y,1, 0);
}

Boundary::~Boundary(){
  // Delete the bounds Cube objects
  delete bounds[+CubeSides::Top];
  delete bounds[+CubeSides::Bottom];
  delete bounds[+CubeSides::Left];
  delete bounds[+CubeSides::Right];
  delete bounds[+CubeSides::Front];
  delete bounds[+CubeSides::Back];
}

void Boundary::draw() const{
  //Draw cubes at the bounding areas
  //TODO: add the image texture to the cubes

  // Store Transform Matrix
  glPushMatrix();

  // Draw the bounds
  bounds[+CubeSides::Top]->draw();
  bounds[+CubeSides::Bottom]->draw();
  bounds[+CubeSides::Left]->draw();
  bounds[+CubeSides::Right]->draw();
  bounds[+CubeSides::Front]->draw();
  bounds[+CubeSides::Back]->draw();

  // Restore Transform Matrix
  glPopMatrix();
}
