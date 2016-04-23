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
    MenuItem* returnToMenu;

    enum options
    {
        ReturnToMenu = 0
    };

    void loadTextures();
    unsigned int textures[3];
};

#endif // _STATSSTATE_H
