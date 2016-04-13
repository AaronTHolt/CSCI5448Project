#include "playablestate.h"

PlayableState::PlayableState(QGLWidget* context) : GameState(context)
{
    loadTexture();

    mouse = false;

    aspectRatio = 1;
    dimension = 15;
    fieldOfView = 55;
    ph = 0;
    th = 0;

    theWorld = World::getWorld();
    if(auto spt = theWorld.lock())
    {
      playerControls = PlayerShipControls(spt->getPlayerShip());
    }
}

void PlayableState::projection()
{
    if(auto spt = theWorld.lock())
    {
      float* transform = new float[16];
      spt->getPlayerShipTransform(transform);
      glMultMatrixf(transform);

      delete transform;
    }
}

void PlayableState::view()
{

}

void PlayableState::draw()
{
    sky(100);

    if (auto spt = theWorld.lock())  // Has to be copied into a shared_ptr before usage
    {
        spt->stepWorld();
        spt->debugDraw();
        spt->draw();
        // spt->playerShip.fireDefaultWeapon();
    }
}

void PlayableState::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Space)
    {
        GameStateContext* context = dynamic_cast<GameStateContext*>(gameStateContext);
        context->setState(context->Welcome);
    }
    else
    {
      playerControls.keyPressEvent(event);
    }
}
