#include "gamestate.h"
#include "../playableObjects/gameObjects/objectLoader/waveOBJ.h"

#include <QDebug>


GameState::GameState(QGLWidget * context)
{
    gameStateContext = context;
}

void GameState::projection()
{
    float zmin = dimension / 4;
    float zmax = 4 * dimension;
    float ydim = zmin * tan(fieldOfView * M_PI / 360.0);
    float xdim = ydim * aspectRatio;
    glFrustum(-xdim, +xdim, -ydim, +ydim, zmin, zmax);
}

void GameState::view()
{
    glTranslated(0, 0, -2 * dimension);
    glRotated(ph, 1, 0, 0);
    glRotated(th, 0, 1, 0);
}

void GameState::lighting()
{
    //  Translate intensity to color vectors
    float Ambient[]  = {0.3, 0.3 ,0.3, 1.0};
    float Diffuse[]  = {0.8, 0.8, 0.8, 1.0};
    float Specular[] = {1.0, 1.0, 1.0, 1.0};
    float Position[] = {0.0, 5.0, 0.0, 1.0};

    //  OpenGL should normalize normal vectors
    glEnable(GL_NORMALIZE);
    //  Enable lighting
    glEnable(GL_LIGHTING);
    //  glColor sets ambient and diffuse color materials
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    //  Enable light 0
    glEnable(GL_LIGHT0);
    //  Set ambient, diffuse, specular components and position of light 0
    glLightfv(GL_LIGHT0,GL_AMBIENT, Ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE, Diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR, Specular);
    glLightfv(GL_LIGHT0,GL_POSITION, Position);
}

void GameState::setAspectRatio(int width, int height)
{
    aspectRatio = height ? width / (float)height : 1;
}

void GameState::mousePressEvent(QMouseEvent* event)
{
   mouse = true;
   pos = event->pos(); //  Remember mouse location
}

void GameState::mouseReleaseEvent(QMouseEvent*)
{
    mouse = false;
}

void GameState::mouseMoveEvent(QMouseEvent* event)
{
   if (mouse)
   {
      QPoint d = event->pos() - pos; //  Change in mouse location

      th = th + d.x() / 2;  //  Translate x movement to azimuth
      if (th > 10)
      {
          th = 10;
      }
      else if (th < -10)
      {
          th = -10;
      }

      ph = ph + d.y() / 2;  //  Translate x movement to azimuth
      if (ph > 10)
      {
          ph = 10;
      }
      else if (ph < -10)
      {
          ph = -10;
      }

      pos = event->pos(); //  Remember new location
   }
}

void GameState::wheelEvent(QWheelEvent* e)
{
   if (e->delta() < 0) //  Zoom out
   {
       dimension += 0.1;
   }
   else if (dimension > 1) //  Zoom in
   {
       dimension -= 0.1;
   }
}

void GameState::highlightOption(int option)
{
    selectableOptions.at(option)->rotate(180.0);
}

void GameState::restoreOption(int option)
{
    selectableOptions.at(option)->rotate(0.0);
}
