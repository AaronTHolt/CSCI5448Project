#include "levelselectstate.h"

LevelSelectState::LevelSelectState(QGLWidget* context) : GameState(context)
{

}

void LevelSelectState::draw()
{
    cube(0.7);
}

void LevelSelectState::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Space)
    {
        GameStateContext* context = dynamic_cast<GameStateContext*>(gameStateContext);
        context->setState(context->Stats);
    }
}
