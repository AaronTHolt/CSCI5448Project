#ifndef _OPTIONSSTATE_H
#define _OPTIONSSTATE_H

#include "gamestate.h"
#include "gamestatecontext.h"

class OptionsState : public GameState
{
public:
    OptionsState(QGLWidget*);
    void draw();
    void keyPressEvent(QKeyEvent*);
};

#endif // _OPTIONSSTATE_H
