#include "gamestate.h"
#include "../playableObjects/gameObjects/objectLoader/waveOBJ.h"

#include <QDebug>


GameState::GameState(QGLWidget * context)
{
    gameStateContext = context;
}
