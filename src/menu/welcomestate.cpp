#include "welcomestate.h"
#include "ship.h"

WelcomeState::WelcomeState(QGLWidget* context) : GameState(context)
{

}

void WelcomeState::draw()
{
    // cube(0.1);
	ship();
}

void WelcomeState::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Space)
    {
        GameStateContext* context = dynamic_cast<GameStateContext*>(gameStateContext);
        context->setState(context->ProfileSelect);
    }
}
