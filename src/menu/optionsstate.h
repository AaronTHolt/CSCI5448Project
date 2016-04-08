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

private:
    Cube* title;

    Cube* returnToMenu;

    enum options
    {
        ReturnToMenu = 0
    };
};

#endif // _OPTIONSSTATE_H
