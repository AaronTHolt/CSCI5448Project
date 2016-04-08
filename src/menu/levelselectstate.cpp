#include "levelselectstate.h"

LevelSelectState::LevelSelectState(QGLWidget* context) : GameState(context)
{
    mouse = false;

    aspectRatio = 1;
    dimension = 3;
    fieldOfView = 55;
    ph = 0;
    th = 0;

    title = new Cube(0.0, 2.1, 0.0,
                     2.0, 0.5, 0.1);

    playGame = new Cube(0.0, 0.9, 0.0,
                        1.2, 0.3, 0.1);
    selectableOptions.append(playGame);

    returnToMenu = new Cube(3.9, -2.5, 0.0,
                            1.2, 0.3, 0.1);
    selectableOptions.append(returnToMenu);

    selectedOption = PlayGame;

    highlightOption(selectedOption);
}

void LevelSelectState::draw()
{
    title->draw();

    for(int i = 0; i < selectableOptions.size(); ++i)
    {
        selectableOptions.at(i)->draw();
    }
}

void LevelSelectState::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Up)
    {
        restoreOption(selectedOption);
        --selectedOption;
        if (selectedOption <= -1)
        {
            selectedOption = selectableOptions.size() - 1;
        }
        highlightOption(selectedOption);
    }
    else if (event->key() == Qt::Key_Down)
    {
        restoreOption(selectedOption);
        ++selectedOption;
        selectedOption = selectedOption % selectableOptions.size();
        highlightOption(selectedOption);
    }
    else if (event->key() == Qt::Key_Return)
    {
        GameStateContext* context = dynamic_cast<GameStateContext*>(gameStateContext);
        if (selectedOption == PlayGame)
        {
            context->setState(context->Playable);
        }
        else if (selectedOption == ReturnToMenu)
        {
            context->setState(context->Welcome);
        }
    }
}
