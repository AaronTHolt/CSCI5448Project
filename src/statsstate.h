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
};

#endif // _STATSSTATE_H
