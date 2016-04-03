#ifndef _GAMESTATE_H
#define _GAMESTATE_H

#include <QGLWidget>
#include <QtOpenGL>

class GameState
{
public:
    GameState(QGLWidget*);
    virtual void draw() = 0;
    virtual void keyPressEvent(QKeyEvent*) = 0;

protected:
    QGLWidget* gameStateContext;

    void cube(float scale = 0.5);
    void ship();
    void asteroid();
};

#endif // _GAMESTATE_H
