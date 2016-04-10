#ifndef _PLAYABLESTATE_H
#define _PLAYABLESTATE_H

#include "gamestate.h"
#include "gamestatecontext.h"
#include "world.h"
#include "playerShipControls.h"

#include <memory>

class PlayableState : public GameState
{
public:
    PlayableState(QGLWidget*);
    void draw();
    void keyPressEvent(QKeyEvent*);
    void view();

private:
    std::weak_ptr<World> theWorld;
    PlayerShipControls playerControls;
};

#endif // _PLAYABLESTATE_H
