#include "statsstate.h"

StatsState::StatsState(QGLWidget* context) : GameState(context)
{
    cube = new Cube(0.0, 0.0, 0.0,
                    0.9, 0.9, 0.9);
}

void StatsState::draw()
{
    cube->draw();
}

void StatsState::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Space)
    {
        GameStateContext* context = dynamic_cast<GameStateContext*>(gameStateContext);
        context->setState(context->Playable);
    }
}
