#ifndef _GAMESTATE_H
#define _GAMESTATE_H

#include <QGLWidget>
#include <QtOpenGL>

#include "cube.h"

class GameState
{
public:
    GameState(QGLWidget*);
    virtual void draw() = 0;
    virtual void keyPressEvent(QKeyEvent*) = 0;

protected:
    QGLWidget* gameStateContext;

    Cube* cube;
};

#endif // _GAMESTATE_H
