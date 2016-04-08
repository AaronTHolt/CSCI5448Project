#ifndef _PROFILESELECTSTATE_H
#define _PROFILESELECTSTATE_H

#include "gamestate.h"
#include "gamestatecontext.h"

class ProfileSelectState : public GameState
{
public:
    ProfileSelectState(QGLWidget*);
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

#endif // _PROFILESELECTSTATE_H
