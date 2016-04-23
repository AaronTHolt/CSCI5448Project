#ifndef _GAMESTATE_H
#define _GAMESTATE_H

#include <QGLWidget>
#include <QtOpenGL>
#include <QString>
#include <QImage>

#include "menuitem.h"
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

    QGLWidget* gameStateContext;
    QVector<MenuItem*> selectableOptions;

    int selectedOption;

    MenuItem* title;
    MenuItem* highlight;

    QPoint  pos;

    bool mouse;
    int fieldOfView;
    int ph;
    int th;
    double dimension;
    double aspectRatio;

    unsigned int skyTexture;

    QImage loadImage(QString name);
    unsigned int loadTexture(QString name);
    void sky(float D = 20);

    void menuItem(double x, double y, double z,
                  double height, double width,
                  unsigned int texture);
};

#endif // _GAMESTATE_H
