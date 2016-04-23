#ifndef _WELCOMESTATE_H
#define _WELCOMESTATE_H

#include "gamestate.h"
#include "gamestatecontext.h"
#include "menuitem.h"

class WelcomeState : public GameState
{
public:
    WelcomeState(QGLWidget*);
    void draw();
    void keyPressEvent(QKeyEvent*);

private:
    MenuItem* playGame;
    MenuItem* changeProfile;
    MenuItem* settings;
    MenuItem* stats;
    MenuItem* exitGame;

    enum options
    {
        PlayGame = 0,
        ChangeProfile = 1,
        Settings = 2,
        Stats = 3,
        ExitGame = 4
    };

    void loadTextures();
    unsigned int textures[7];
};

#endif // _WELCOMESTATE_H
