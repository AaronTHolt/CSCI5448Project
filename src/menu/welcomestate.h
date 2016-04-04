#ifndef _WELCOMESTATE_H
#define _WELCOMESTATE_H

#include "gamestate.h"
#include "gamestatecontext.h"

class WelcomeState : public GameState
{
public:
    WelcomeState(QGLWidget*);
    void draw();
    void keyPressEvent(QKeyEvent*);

private:
    void highlightOption(int option);
    void restoreOption(int option);

    Cube* title;

    Cube* playGame;
    Cube* changeProfile;
    Cube* settings;
    Cube* stats;
    Cube* exitGame;
    QVector<Cube*> selectableOptions;

    int selectedOption;
};

#endif // _WELCOMESTATE_H
