#ifndef _GAMESTATECONTEXT_H
#define _GAMESTATECONTEXT_H

#include <QtOpenGL>
#include <QTimer>
#include <QElapsedTimer>

#include "gamestate.h"
#include "welcomestate.h"
#include "profileselectstate.h"
#include "optionsstate.h"
#include "levelselectstate.h"
#include "statsstate.h"
#include "playablestate.h"

class GameStateContext : public QGLWidget
{
public:
    enum GameStates
    {
        Welcome,
        ProfileSelect,
        Options,
        LevelSelect,
        Stats,
        Playable
    };

    GameStateContext();
    void draw();
    void setState(GameStates);

private:
    bool init;
    bool mouse;
    int fov;
    int ph;
    int th;
    double dim;
    double asp;

    GameState* welcomeState;
    GameState* profileSelectState;
    GameState* optionsState;
    GameState* levelSelectState;
    GameState* statsState;
    GameState* playableState;

    GameStates currentGameState;

    QVector<GameState*> states;

    QTimer timer;
    QElapsedTimer time;
    QPoint  pos;

    void initializeStates();
    void Projection();

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void keyPressEvent(QKeyEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void wheelEvent(QWheelEvent*);


};

#endif // _GAMESTATECONTEXT_H
