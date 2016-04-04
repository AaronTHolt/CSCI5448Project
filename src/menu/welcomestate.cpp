#include "welcomestate.h"

WelcomeState::WelcomeState(QGLWidget* context) : GameState(context)
{
    cube = new Cube(0.0, 0.0, 0.0,
                    0.1, 0.1, 0.1);
}

void WelcomeState::draw()
{
    cube->draw();
}

void WelcomeState::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Space)
    {
        GameStateContext* context = dynamic_cast<GameStateContext*>(gameStateContext);
        context->setState(context->ProfileSelect);
    }
}
