#include "boundary.h"

#include "boundaryPhysicsObject.h"

#include <QGLWidget>

Boundary::Boundary(CubeSides side){
  type = GameObjectType::Boundary;
  // Half lengths of the dimensions of the play area
  x = dim;
  y = dim;
  z = dim;
  float width = 0.5;
  Vector3 pos;
  switch(side){
  case CubeSides::Top:
    pos = Vector3(0,y,0);
    y = width;
    break;
  case CubeSides::Bottom:
    pos = Vector3(0,-y,0);
    y = width;
    break;
  case CubeSides::Left:
    pos = Vector3(-x,0,0);
    x = width;
    break;
  case CubeSides::Right:
    pos = Vector3(x,0,0);
    x = width;
    break;
  case CubeSides::Front:
    pos = Vector3(0,0,z);
    z = width;
    break;
  case CubeSides::Back:
    pos = Vector3(0,0,-z);
    z = width;
    break;
  }
  // Construct the physics object for the boundary to the play area
  physicsObject = new BoundaryPhysicsObject(x,y,z, pos, this);

  // Construct the Boundary object for drawing
  bound = new Cube(pos.getX(), pos.getY(), pos.getZ(), x,y,z, 0);
}

double Boundary::getDim(){
  return dim;
}

Boundary::~Boundary(){
  // Delete the bound Cube objects
  delete bound;
}

void Boundary::draw() const{
  //Draw cubes at the bounding areas
  //TODO: add the image texture to the cubes

  // Store Transform Matrix
  glPushMatrix();
  /*
  // Draw the bounds
  bounds[+CubeSides::Top]->draw();
  bounds[+CubeSides::Bottom]->draw();
  bounds[+CubeSides::Left]->draw();
  bounds[+CubeSides::Right]->draw();
  bounds[+CubeSides::Front]->draw();
  bounds[+CubeSides::Back]->draw();
  */
  // Restore Transform Matrix
  glPopMatrix();
}

bool Boundary::onCollision(GameObjectType got){
  return false;
}
