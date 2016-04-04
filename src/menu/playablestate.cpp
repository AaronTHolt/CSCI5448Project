#include "playablestate.h"

PlayableState::PlayableState(QGLWidget* context) : GameState(context)
{
    cube = new Cube(0.0, 0.0, 0.0,
                    1.1, 1.1, 1.1);
}

void PlayableState::draw()
{
    cube->draw();
}

void PlayableState::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Space)
    {
        GameStateContext* context = dynamic_cast<GameStateContext*>(gameStateContext);
        context->setState(context->Welcome);
    }
}
