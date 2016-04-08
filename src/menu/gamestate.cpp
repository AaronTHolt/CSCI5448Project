#include "gamestate.h"
#include "../playableObjects/gameObjects/objectLoader/waveOBJ.h"

#include <QDebug>


GameState::GameState(QGLWidget * context)
{
    gameStateContext = context;
}

void GameState::highlightOption(int option)
{
    selectableOptions.at(option)->rotate(180.0);
}

void GameState::restoreOption(int option)
{
    selectableOptions.at(option)->rotate(0.0);
}
