#include "profileselectstate.h"

ProfileSelectState::ProfileSelectState(QGLWidget* context) : GameState(context)
{

}

void ProfileSelectState::draw()
{
    cube(0.3);
}

void ProfileSelectState::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Space)
    {
        GameStateContext* context = dynamic_cast<GameStateContext*>(gameStateContext);
        context->setState(context->Options);
    }
}
