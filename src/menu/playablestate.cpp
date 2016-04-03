#include "playablestate.h"

PlayableState::PlayableState(QGLWidget* context) : GameState(context)
{
    theWorld = World::getWorld();
}

void PlayableState::draw()
{
    if (auto spt = theWorld.lock()) { // Has to be copied into a shared_ptr before usage
        spt->draw();
    }
    
}

void PlayableState::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Space)
    {
        GameStateContext* context = dynamic_cast<GameStateContext*>(gameStateContext);
        context->setState(context->Welcome);
    }
}
