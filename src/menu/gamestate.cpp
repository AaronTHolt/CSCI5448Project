#include "gamestate.h"
#include "../playableObjects/gameObjects/objectLoader/waveOBJ.h"

#include <QDebug>


GameState::GameState(QGLWidget * context)
{
    gameStateContext = context;
}

void GameState::projection()
{
    float zmin = dimension / 20;
    float zmax = 20 * dimension;
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
    highlight->setDimension(selectableOptions.at(option)->getWidth() * 1.2,
                            selectableOptions.at(option)->getHeight() * 1.2);

    highlight->setPosition(selectableOptions.at(option)->getPositionX(),
                           selectableOptions.at(option)->getPositionY(),
                           selectableOptions.at(option)->getPositionZ() - 0.1);
}

QImage GameState::loadImage(QString name)
{
    QImage image;
    if(!image.load(name))
    {
        qDebug() << "Error loading image: " << name;
        exit(1);
    }

    QImage formatted_image;
    formatted_image = QGLWidget::convertToGLFormat(image);
    if(formatted_image.isNull())
    {
        qDebug("Error with formatted_image");
        exit(1);
    }
    return formatted_image;
}

unsigned int GameState::loadTexture(QString name)
{
    unsigned int texture;

    QImage formatted_image = loadImage(name);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
            formatted_image.width(), formatted_image.height(),
            0, GL_RGBA, GL_UNSIGNED_BYTE, formatted_image.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    return texture;
}

void GameState::sky(float D)
{
    glPushMatrix();

    glColor3f(1,1,1);
    glEnable(GL_TEXTURE_2D);

    glBindTexture( GL_TEXTURE_2D, skyTexture );

    glBegin(GL_QUADS);
    glNormal3f(0, 0, 1);
    glTexCoord2f(0.0,0.5); glVertex3f(-D,-D,-D);
    glTexCoord2f(0.25,0.5); glVertex3f(+D,-D,-D);
    glTexCoord2f(0.25,0.75); glVertex3f(+D,+D,-D);
    glTexCoord2f(0.0,0.75); glVertex3f(-D,+D,-D);

    glNormal3f(-1, 0, 0);
    glTexCoord2f(0.25,0.5); glVertex3f(+D,-D,-D);
    glTexCoord2f(0.5,0.5); glVertex3f(+D,-D,+D);
    glTexCoord2f(0.5,0.75); glVertex3f(+D,+D,+D);
    glTexCoord2f(0.25,0.75); glVertex3f(+D,+D,-D);

    glNormal3f(0, 0, -1);
    glTexCoord2f(0.5,0.5); glVertex3f(+D,-D,+D);
    glTexCoord2f(0.75,0.5); glVertex3f(-D,-D,+D);
    glTexCoord2f(0.75,0.75); glVertex3f(-D,+D,+D);
    glTexCoord2f(0.5,0.75); glVertex3f(+D,+D,+D);

    glNormal3f(1, 0, 0);
    glTexCoord2f(0.75,0.5); glVertex3f(-D,-D,+D);
    glTexCoord2f(1.0,0.5); glVertex3f(-D,-D,-D);
    glTexCoord2f(1.0,0.75); glVertex3f(-D,+D,-D);
    glTexCoord2f(0.75,0.75); glVertex3f(-D,+D,+D);

    glNormal3f(0, -1, 0);
    glTexCoord2f(0.25,0.75); glVertex3f(+D,+D,-D);
    glTexCoord2f(0.5,0.75); glVertex3f(+D,+D,+D);
    glTexCoord2f(0.5,1.0); glVertex3f(-D,+D,+D);
    glTexCoord2f(0.25,1.0); glVertex3f(-D,+D,-D);

    glNormal3f(0, 1, 0);
    glTexCoord2f(0.25,0.5); glVertex3f(+D,-D,-D);
    glTexCoord2f(0.5,0.5); glVertex3f(+D,-D,+D);
    glTexCoord2f(0.5,0.25); glVertex3f(-D,-D,+D);
    glTexCoord2f(0.25,0.25); glVertex3f(-D,-D,-D);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void GameState::keyReleaseEvent(QKeyEvent* event){
  event->key();
}
