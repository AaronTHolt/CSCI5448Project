#include "levelselectstate.h"

LevelSelectState::LevelSelectState(QGLWidget* context) : GameState(context)
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

    returnToMenu = new MenuItem();
    returnToMenu ->setPosition(3.9, -2.5, 0.0);
    returnToMenu ->setDimension(2.4, 0.6);
    returnToMenu->setTexture(textures[2]);
    selectableOptions.append(returnToMenu);

    highlight = new MenuItem();
    highlight->setTexture(textures[3]);

    selectedOption = PlayGame;
}

void LevelSelectState::draw()
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

void LevelSelectState::keyPressEvent(QKeyEvent* event)
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
            context->setState(context->Playable);
        }
        else if (selectedOption == ReturnToMenu)
        {
            context->setState(context->Welcome);
        }
    }
}

void LevelSelectState::loadTextures()
{
    skyTexture = loadTexture(":/spaceSkybox.bmp");
    textures[0] = loadTexture(QString(":/level_select.bmp"));
    textures[1] = loadTexture(QString(":/play_game.bmp"));
    textures[2] = loadTexture(QString(":/return_to_menu.bmp"));
    textures[3] = loadTexture(QString(":/highlight.bmp"));
}
