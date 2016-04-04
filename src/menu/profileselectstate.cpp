#include "profileselectstate.h"

ProfileSelectState::ProfileSelectState(QGLWidget* context) : GameState(context)
{
    cube = new Cube(0.0, 0.0, 0.0,
                    0.3, 0.3, 0.3);
}

void ProfileSelectState::draw()
{
    cube->draw();
}

void ProfileSelectState::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Space)
    {
        GameStateContext* context = dynamic_cast<GameStateContext*>(gameStateContext);
        context->setState(context->Options);
    }
}
