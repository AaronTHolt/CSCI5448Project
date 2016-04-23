#include "welcomestate.h"
#include "ship.h"

WelcomeState::WelcomeState(QGLWidget* context) : GameState(context)
{
    loadTextures();

    mouse = false;

    aspectRatio = 1;
    dimension = 3;
    fieldOfView = 55;
    ph = 0;
    th = 0;

    title = new MenuItem();
    title ->setPosition(0.0, 2.1, 0.0);
    title ->setDimension(5.0, 1.2);
    title->setTexture(textures[0]);

    playGame = new MenuItem();
    playGame ->setPosition(0.0, 0.9, 0.0);
    playGame ->setDimension(2.4, 0.6);
    playGame->setTexture(textures[1]);
    selectableOptions.append(playGame);

    changeProfile = new MenuItem();
    changeProfile ->setPosition(0.0, 0.1, 0.0);
    changeProfile ->setDimension(2.4, 0.6);
    changeProfile->setTexture(textures[2]);
    selectableOptions.append(changeProfile);

    settings = new MenuItem();
    settings ->setPosition(0.0, -0.7, 0.0);
    settings ->setDimension(2.4, 0.6);
    settings->setTexture(textures[3]);
    selectableOptions.append(settings);

    stats = new MenuItem();
    stats ->setPosition(0.0, -1.5, 0.0);
    stats ->setDimension(2.4, 0.6);
    stats->setTexture(textures[4]);
    selectableOptions.append(stats);

    exitGame = new MenuItem();
    exitGame ->setPosition(0.0, -2.3, 0.0);
    exitGame ->setDimension(2.4, 0.6);
    exitGame->setTexture(textures[5]);
    selectableOptions.append(exitGame);

    highlight = new MenuItem();
    highlight->setTexture(textures[6]);

    selectedOption = PlayGame;
}

void WelcomeState::draw()
{
    sky();

    title->display();

    highlightOption(selectedOption);

    highlight->display();

    for(int i = 0; i < selectableOptions.size(); ++i)
    {
        selectableOptions.at(i)->display();
    }
}

void WelcomeState::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Up)
    {
        --selectedOption;
        if (selectedOption <= -1)
        {
            selectedOption = selectableOptions.size() - 1;
        }
    }
    else if (event->key() == Qt::Key_Down)
    {
        ++selectedOption;
        selectedOption = selectedOption % selectableOptions.size();
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

void WelcomeState::loadTextures()
{
    skyTexture = loadTexture(":/spaceSkybox.bmp");
    textures[0] = loadTexture(QString(":/title.bmp"));
    textures[1] = loadTexture(QString(":/play_game.bmp"));
    textures[2] = loadTexture(QString(":/change_profile.bmp"));
    textures[3] = loadTexture(QString(":/settings.bmp"));
    textures[4] = loadTexture(QString(":/stats.bmp"));
    textures[5] = loadTexture(QString(":/exit_game.bmp"));
    textures[6] = loadTexture(QString(":/highlight.bmp"));
}
