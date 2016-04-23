#include "optionsstate.h"

OptionsState::OptionsState(QGLWidget* context) : GameState(context)
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

    returnToMenu = new MenuItem();
    returnToMenu ->setPosition(3.9, -2.5, 0.0);
    returnToMenu ->setDimension(2.4, 0.6);
    returnToMenu->setTexture(textures[1]);
    selectableOptions.append(returnToMenu);

    highlight = new MenuItem();
    highlight->setTexture(textures[2]);

    selectedOption = ReturnToMenu;
}

void OptionsState::draw()
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

void OptionsState::keyPressEvent(QKeyEvent* event)
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
        if (selectedOption == ReturnToMenu)
        {
            context->setState(context->Welcome);
        }
    }
}

void OptionsState::loadTextures()
{
    skyTexture = loadTexture(":/spaceSkybox.bmp");
    textures[0] = loadTexture(QString(":/settings.bmp"));
    textures[1] = loadTexture(QString(":/return_to_menu.bmp"));
    textures[2] = loadTexture(QString(":/highlight.bmp"));
}
