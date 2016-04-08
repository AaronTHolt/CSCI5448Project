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

private:
    Cube* title;

    Cube* playGame;
    Cube* changeProfile;
    Cube* settings;
    Cube* stats;
    Cube* exitGame;

    enum options
    {
        PlayGame = 0,
        ChangeProfile = 1,
        Settings = 2,
        Stats = 3,
        ExitGame = 4
    };
};

#endif // _WELCOMESTATE_H
