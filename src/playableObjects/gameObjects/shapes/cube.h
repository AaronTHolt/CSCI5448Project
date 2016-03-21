//
//  Cube class
//  The constructor sets the size and rotation
//  All parameters are assigned default values
//
//  Modified from Example 1 from
//  Willem A. (Vlakkies) Schreuder
//  CSCI4239/5239 Spring 2016
//
#ifndef _CUBE_H_
#define _CUBE_H_

//  The cube class is used for the boundary walls
class Cube
{
 private:
  float x,y,z;     //  Position of the cube (x,y,z)
  float Sx,Sy,Sz;  //  Dimensions in X/Y/Z directions
  float Th;        //  Rotation around Y axis
 public:
  Cube(float x=0, float y=0, float z=0,
       float dx=1,float dy=1,float dz=1,
       float th=0);
  void translate(float x, float y, float z); //  Set location
  void rotate(float th);                     //  Set rotation
  void scale(float dx,float dy,float dz);    //  Set scale
  void draw(float x, float y, float z);      //  Render the cube
};

#endif
