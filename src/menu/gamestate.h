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
    void highlightOption(int option);
    void restoreOption(int option);

    QGLWidget* gameStateContext;
    QVector<Cube*> selectableOptions;

    int selectedOption;
};

#endif // _GAMESTATE_H
