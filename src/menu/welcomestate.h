#ifndef _WELCOMESTATE_H
#define _WELCOMESTATE_H

#include "gamestate.h"
#include "gamestatecontext.h"

class WelcomeState : public GameState
{
public:
    WelcomeState(QGLWidget*);
    void draw();
    void keyPressEvent(QKeyEvent*);
};

#endif // _WELCOMESTATE_H
