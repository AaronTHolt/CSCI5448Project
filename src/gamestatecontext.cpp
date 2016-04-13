#include "gamestatecontext.h"

GameStateContext::GameStateContext()
{
    setFocusPolicy(Qt::StrongFocus);

    init = false;

    currentGameState = Welcome;
}

GameStateContext::~GameStateContext()
{

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

void GameStateContext::exitApplication()
{
    QCoreApplication::quit();
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

void GameStateContext::initializeGL()
{
   if (init)
   {
       return;
   }
   init = true;

   glEnable(GL_DEPTH_TEST);

   initializeStates();

   //  Start 100 fps timer connected to updateGL
   timer.setInterval(10);
   connect(&timer,SIGNAL(timeout()),this,SLOT(updateGL()));
   timer.start();
   time.start();
}

void GameStateContext::resizeGL(int width, int height)
{    
    for (int i = 0; i < states.size(); ++i)
    {
        states.at(i)->setAspectRatio(width, height);
    }
    //  Viewport is whole screen
    glViewport(0,0,width,height);
    //  Set projection
    Projection();
}

void GameStateContext::Projection()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    states.at(currentGameState)->projection();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GameStateContext::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Projection();
    //glLoadIdentity();

    states.at(currentGameState)->view();
    states.at(currentGameState)->lighting();
    states.at(currentGameState)->draw();
}

void GameStateContext::keyPressEvent(QKeyEvent* event)
{
    states.at(currentGameState)->keyPressEvent(event);
}

void GameStateContext::mousePressEvent(QMouseEvent* event)
{
    states.at(currentGameState)->mousePressEvent(event);
}

void GameStateContext::mouseReleaseEvent(QMouseEvent* event)
{
    states.at(currentGameState)->mouseReleaseEvent(event);
}

void GameStateContext::mouseMoveEvent(QMouseEvent* event)
{
   states.at(currentGameState)->mouseMoveEvent(event);
}

void GameStateContext::wheelEvent(QWheelEvent* event)
{
   states.at(currentGameState)->wheelEvent(event);
}
