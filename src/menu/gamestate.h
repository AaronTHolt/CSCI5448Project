#ifndef _GAMESTATE_H
#define _GAMESTATE_H

#include <QGLWidget>
#include <QtOpenGL>

#include "cube.h"

class GameState
{
public:
    GameState(QGLWidget*);
    virtual void projection();
    virtual void view();
    virtual void lighting();
    virtual void setAspectRatio(int width, int height);
    virtual void draw() = 0;
    virtual void keyPressEvent(QKeyEvent*) = 0;
    virtual void mousePressEvent(QMouseEvent*);
    virtual void mouseReleaseEvent(QMouseEvent*);
    virtual void mouseMoveEvent(QMouseEvent*);
    virtual void wheelEvent(QWheelEvent*);

protected:
    virtual void highlightOption(int option);
    virtual void restoreOption(int option);

    QGLWidget* gameStateContext;
    QVector<Cube*> selectableOptions;

    int selectedOption;

    QPoint  pos;

    bool mouse;
    int fieldOfView;
    int ph;
    int th;
    double dimension;
    double aspectRatio;
};

#endif // _GAMESTATE_H
