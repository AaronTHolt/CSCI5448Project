#ifndef _STATSSTATE_H
#define _STATSSTATE_H

#include "gamestate.h"
#include "gamestatecontext.h"

class StatsState : public GameState
{
public:
    StatsState(QGLWidget*);
    void draw();
    void keyPressEvent(QKeyEvent*);

private:
    Cube* title;

    Cube* returnToMenu;

    enum options
    {
        ReturnToMenu = 0
    };
};

#endif // _STATSSTATE_H
