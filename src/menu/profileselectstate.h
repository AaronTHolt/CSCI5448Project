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
};

#endif // _PROFILESELECTSTATE_H
