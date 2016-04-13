#include "welcomestate.h"
#include "ship.h"

WelcomeState::WelcomeState(QGLWidget* context) : GameState(context)
{
    loadTexture();

    mouse = false;

    aspectRatio = 1;
    dimension = 3;
    fieldOfView = 55;
    ph = 0;
    th = 0;

    title = new Cube(0.0, 2.1, 0.0,
                     2.5, 0.6, 0.1);

    playGame = new Cube(0.0, 0.9, 0.0,
                        1.2, 0.3, 0.1);
    selectableOptions.append(playGame);

    changeProfile = new Cube(0.0, 0.1, 0.0,
                             1.2, 0.3, 0.1);
    selectableOptions.append(changeProfile);

    settings = new Cube(0.0, -0.7, 0.0,
                        1.2, 0.3, 0.1);
    selectableOptions.append(settings);

    stats = new Cube(0.0, -1.5, 0.0,
                     1.2, 0.3, 0.1);
    selectableOptions.append(stats);

    exitGame = new Cube(0.0, -2.3, 0.0,
                        1.2, 0.3, 0.1);
    selectableOptions.append(exitGame);

    selectedOption = PlayGame;

    highlightOption(selectedOption);
}

void WelcomeState::draw()
{
    sky();

    title->draw();

    for(int i = 0; i < selectableOptions.size(); ++i)
    {
        selectableOptions.at(i)->draw();
    }
}

void WelcomeState::keyPressEvent(QKeyEvent* event)
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
            context->setState(context->LevelSelect);
        }
        else if (selectedOption == ChangeProfile)
        {
            context->setState(context->ProfileSelect);
        }
        else if (selectedOption == Settings)
        {
            context->setState(context->Options);
        }
        else if (selectedOption == Stats)
        {
            context->setState(context->Stats);
        }
        else if (selectedOption == ExitGame)
        {
            context->exitApplication();
        }
    }
}
