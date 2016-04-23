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
    MenuItem* returnToMenu;

    enum options
    {
        ReturnToMenu = 0
    };

    void loadTextures();
    unsigned int textures[3];
};

#endif // _OPTIONSSTATE_H
