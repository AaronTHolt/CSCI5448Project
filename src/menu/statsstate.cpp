#include "statsstate.h"

StatsState::StatsState(QGLWidget* context) : GameState(context)
{

}

void StatsState::draw()
{
    cube(0.9);
}

void StatsState::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Space)
    {
        GameStateContext* context = dynamic_cast<GameStateContext*>(gameStateContext);
        context->setState(context->Playable);
    }
}
