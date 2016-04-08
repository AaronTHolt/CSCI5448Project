#ifndef _LEVELSELECTSTATE_H
#define _LEVELSELECTSTATE_H

#include "gamestate.h"
#include "gamestatecontext.h"

class LevelSelectState : public GameState
{
public:
    LevelSelectState(QGLWidget*);
    void draw();
    void keyPressEvent(QKeyEvent*);

private:
    Cube* title;

    Cube* playGame;
    Cube* returnToMenu;

    enum options
    {
        PlayGame = 0,
        ReturnToMenu = 1
    };
};

#endif // _LEVELSELECTSTATE_H
