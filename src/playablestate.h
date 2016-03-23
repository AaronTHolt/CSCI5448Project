#ifndef _PLAYABLESTATE_H
#define _PLAYABLESTATE_H

#include "gamestate.h"
#include "gamestatecontext.h"

class PlayableState : public GameState
{
public:
    PlayableState(QGLWidget*);
    void draw();
    void keyPressEvent(QKeyEvent*);
};

#endif // _PLAYABLESTATE_H
