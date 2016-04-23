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
    MenuItem* playGame;
    MenuItem* returnToMenu;

    enum options
    {
        PlayGame = 0,
        ReturnToMenu = 1
    };

    void loadTextures();
    unsigned int textures[4];
};

#endif // _LEVELSELECTSTATE_H
