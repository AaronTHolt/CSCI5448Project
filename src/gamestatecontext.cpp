#include "gamestatecontext.h"
#include <iostream>

GameStateContext::GameStateContext()
{
    setFocusPolicy(Qt::StrongFocus);

    init = false;
    mouse = false;

    asp = 1;
    dim = 3;
    fov = 55;
    ph = 0;
    th = 0;

    initializeStates();

    currentGameState = Welcome;
}

void GameStateContext::initializeStates()
{
    welcomeState = new WelcomeState(this);
    states.insert(Welcome, welcomeState);

    profileSelectState = new ProfileSelectState(this);
    states.insert(ProfileSelect, profileSelectState);

    optionsState = new OptionsState(this);
    states.insert(Options, optionsState);

    levelSelectState = new LevelSelectState(this);
    states.insert(LevelSelect, levelSelectState);

    statsState = new StatsState(this);
    states.insert(Stats, statsState);

    playableState = new PlayableState(this);
    states.insert(Playable, playableState);
}

void GameStateContext::draw()
{
    states.at(currentGameState)->draw();
}

void GameStateContext::setState(GameStates state)
{
    switch(state)
    {
        case Welcome:
        case ProfileSelect:
        case Options:
        case LevelSelect:
        case Stats:
        case Playable:
            currentGameState = state;
            break;
        default:
            currentGameState = Welcome;
            break;

    }
}

void GameStateContext::initializeGL()
{
   if (init)
   {
       return;
   }
   init = true;

   glEnable(GL_DEPTH_TEST);

   //  Start 100 fps timer connected to updateGL
   timer.setInterval(10);
   connect(&timer,SIGNAL(timeout()),this,SLOT(updateGL()));
   timer.start();
   time.start();
}

void GameStateContext::resizeGL(int width, int height)
{
   //  Window aspect ration
   asp = height ? width / (float)height : 1;
   //  Viewport is whole screen
   glViewport(0,0,width,height);
   //  Set projection
   Projection();
}

void GameStateContext::Projection()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float zmin = dim / 4;
    float zmax = 4 * dim;
    float ydim = zmin * tan(fov * M_PI / 360.0);
    float xdim = ydim * asp;
    glFrustum(-xdim, +xdim, -ydim, +ydim, zmin, zmax);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    }

void GameStateContext::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //  Set projection
    Projection();
    //  Set view
    glLoadIdentity();
    if (fov) glTranslated(0, 0, -2 * dim);
    glRotated(ph, 1, 0, 0);
    glRotated(th, 0, 1, 0);

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

    draw();

    //  Disable lighting
    glDisable(GL_LIGHTING);
}

void GameStateContext::keyPressEvent(QKeyEvent* event)
{
    states.at(currentGameState)->keyPressEvent(event);
}

void GameStateContext::mousePressEvent(QMouseEvent* event)
{
//   mouse = true;
//   pos = event->pos(); //  Remember mouse location
}

void GameStateContext::mouseReleaseEvent(QMouseEvent*)
{
//    mouse = false;
}

void GameStateContext::mouseMoveEvent(QMouseEvent* event)
{
//   if (mouse)
//   {
//      QPoint d = event->pos() - pos; //  Change in mouse location
//      th = (th + d.x()) % 360; //  Translate x movement to azimuth
//      ph = (ph + d.y()) % 360; //  Translate y movement to elevation
//      pos = event->pos(); //  Remember new location
//      updateGL(); //  Request redisplay
//   }
}

void GameStateContext::wheelEvent(QWheelEvent* e)
{
//   if (e->delta() < 0) //  Zoom out
//   {
//       dim += 0.1;
//   }
//   else if (dim > 1) //  Zoom in
//   {
//       dim -= 0.1;
//   }
//   updateGL();
}
