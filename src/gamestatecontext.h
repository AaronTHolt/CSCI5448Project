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
    ~GameStateContext();

    void setState(GameStates);
    void exitApplication();

private:
    bool init;

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

    void initializeStates();
    void Projection();

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void keyPressEvent(QKeyEvent*);
    void keyReleaseEvent(QKeyEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void wheelEvent(QWheelEvent*);


};

#endif // _GAMESTATECONTEXT_H
