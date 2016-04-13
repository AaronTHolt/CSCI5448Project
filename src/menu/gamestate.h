#ifndef _GAMESTATE_H
#define _GAMESTATE_H

#include <QGLWidget>
#include <QtOpenGL>

#include "cube.h"

class GameState
{
public:
    GameState(QGLWidget*);
    void projection();
    void view();
    void lighting();
    void setAspectRatio(int width, int height);
    virtual void draw() = 0;
    virtual void keyPressEvent(QKeyEvent*) = 0;
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void wheelEvent(QWheelEvent*);

protected:
    void highlightOption(int option);
    void restoreOption(int option);

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

    unsigned int textures[1];

    void loadTexture();
    void sky(float D = 20);
};

#endif // _GAMESTATE_H
