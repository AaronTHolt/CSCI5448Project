//
//  Cube class
//
//  Modified from Example 1 from
//  Willem A. (Vlakkies) Schreuder
//  CSCI4239/5239 Spring 2016
//

#include "cube.h"

#include <QGLWidget>
//
//  Constructor
//
Cube::Cube(float x0, float y0, float z0, float dx,float dy,float dz,float th)
{
   x  = x0;
   y  = y0;
   z  = z0;
   Sx = dx;
   Sy = dy;
   Sz = dz;
   Th = th;
}

//
//  Set location
//
void Cube::translate(float x0, float y0, float z0)
{
  x = x0;
  y = y0;
  z = z0;
}

//
//  Set rotation
//
void Cube::rotate(float th)
{
   Th = th;
}

//
//  Set scaling
//
void Cube::scale(float dx,float dy,float dz)
{
   Sx = dx;
   Sy = dy;
   Sz = dz;
}

//
//  Display the cube
//
void Cube::draw()
{
   //  Save transformation
   glPushMatrix();
   //  Offset, scale and rotate
   glTranslated(x,y,z);
   glRotated(Th,0,1,0);
   glScaled(Sx,Sy,Sz);
   //  Cube
   glBegin(GL_QUADS);
   //  Front
   glColor3f(1,0,0);
   glNormal3f( 0, 0, 1);
   glVertex3f(-1,-1, 1);
   glVertex3f(+1,-1, 1);
   glVertex3f(+1,+1, 1);
   glVertex3f(-1,+1, 1);
   //  Back
   glColor3f(0,0,1);
   glNormal3f( 0, 0,-1);
   glVertex3f(+1,-1,-1);
   glVertex3f(-1,-1,-1);
   glVertex3f(-1,+1,-1);
   glVertex3f(+1,+1,-1);
   //  Right
   glColor3f(1,1,0);
   glNormal3f(+1, 0, 0);
   glVertex3f(+1,-1,+1);
   glVertex3f(+1,-1,-1);
   glVertex3f(+1,+1,-1);
   glVertex3f(+1,+1,+1);
   //  Left
   glColor3f(0,1,0);
   glNormal3f(-1, 0, 0);
   glVertex3f(-1,-1,-1);
   glVertex3f(-1,-1,+1);
   glVertex3f(-1,+1,+1);
   glVertex3f(-1,+1,-1);
   //  Top
   glColor3f(0,1,1);
   glNormal3f( 0,+1, 0);
   glVertex3f(-1,+1,+1);
   glVertex3f(+1,+1,+1);
   glVertex3f(+1,+1,-1);
   glVertex3f(-1,+1,-1);
   //  Bottom
   glColor3f(1,0,1);
   glNormal3f( 0,-1, 0);
   glVertex3f(-1,-1,-1);
   glVertex3f(+1,-1,-1);
   glVertex3f(+1,-1,+1);
   glVertex3f(-1,-1,+1);
   //  End
   glEnd();
   //  Undo transofrmations
   glPopMatrix();
}
