#include "optionsstate.h"

OptionsState::OptionsState(QGLWidget* context) : GameState(context)
{
    title = new Cube(0.0, 2.1, 0.0,
                     2.0, 0.5, 0.1);

    returnToMenu = new Cube(3.9, -2.5, 0.0,
                            1.2, 0.3, 0.1);
    selectableOptions.append(returnToMenu);

    selectedOption = ReturnToMenu;

    highlightOption(selectedOption);
}

void OptionsState::draw()
{
    title->draw();

    for(int i = 0; i < selectableOptions.size(); ++i)
    {
        selectableOptions.at(i)->draw();
    }
}

void OptionsState::keyPressEvent(QKeyEvent* event)
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
        if (selectedOption == ReturnToMenu)
        {
            context->setState(context->Welcome);
        }
    }
}
