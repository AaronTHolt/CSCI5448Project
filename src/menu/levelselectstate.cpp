#include "levelselectstate.h"

LevelSelectState::LevelSelectState(QGLWidget* context) : GameState(context)
{
    cube = new Cube(0.0, 0.0, 0.0,
                    0.7, 0.7, 0.7);
}

void LevelSelectState::draw()
{
    cube->draw();
}

void LevelSelectState::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Space)
    {
        GameStateContext* context = dynamic_cast<GameStateContext*>(gameStateContext);
        context->setState(context->Stats);
    }
}
