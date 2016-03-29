#include "playablestate.h"

PlayableState::PlayableState(QGLWidget* context) : GameState(context)
{

}

void PlayableState::draw()
{
    cube(1.1);
}

void PlayableState::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Space)
    {
        GameStateContext* context = dynamic_cast<GameStateContext*>(gameStateContext);
        context->setState(context->Welcome);
    }
}
