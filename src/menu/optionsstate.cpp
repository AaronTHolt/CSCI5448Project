#include "optionsstate.h"

OptionsState::OptionsState(QGLWidget* context) : GameState(context)
{
    cube = new Cube(0.0, 0.0, 0.0,
                    0.5, 0.5, 0.5);
}

void OptionsState::draw()
{
    cube->draw();
}

void OptionsState::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Space)
    {
        GameStateContext* context = dynamic_cast<GameStateContext*>(gameStateContext);
        context->setState(context->LevelSelect);
    }
}
