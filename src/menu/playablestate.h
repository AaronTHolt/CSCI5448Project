#ifndef _PLAYABLESTATE_H
#define _PLAYABLESTATE_H

#include "gamestate.h"
#include "gamestatecontext.h"
#include "world.h"

#include <memory>

class PlayableState : public GameState
{
public:
    PlayableState(QGLWidget*);
    void draw();
    void keyPressEvent(QKeyEvent*);

private:
    std::weak_ptr<World> theWorld;
};

#endif // _PLAYABLESTATE_H
