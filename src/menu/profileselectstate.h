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
    MenuItem* returnToMenu;

    enum options
    {
        ReturnToMenu = 0
    };

    void loadTextures();
    unsigned int textures[3];
};

#endif // _PROFILESELECTSTATE_H
