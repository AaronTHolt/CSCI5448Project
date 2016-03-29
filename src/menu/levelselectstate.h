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
};

#endif // _LEVELSELECTSTATE_H
