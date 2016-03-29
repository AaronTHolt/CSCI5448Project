#include "optionsstate.h"

OptionsState::OptionsState(QGLWidget* context) : GameState(context)
{

}

void OptionsState::draw()
{
    cube(0.5);
}

void OptionsState::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Space)
    {
        GameStateContext* context = dynamic_cast<GameStateContext*>(gameStateContext);
        context->setState(context->LevelSelect);
    }
}
