#include "playablestate.h"

PlayableState::PlayableState(QGLWidget* context) : GameState(context)
{
    loadTexture();

    mouse = false;

    aspectRatio = 1;
    fieldOfView = 55;

    cameraDistance = 4.0;
    cameraHeight = 1.5;

    theWorld = World::getWorld();
    if(auto spt = theWorld.lock())
    {
      playerControls = PlayerShipControls(spt->getPlayerShip());
    }
}

void PlayableState::projection()
{
    gluPerspective(fieldOfView, aspectRatio, 0.1, 1000);
}

void PlayableState::view()
{
    if(auto spt = theWorld.lock())
    {
      shipPosition = spt->getPlayerShip()->getPhysicsObject().getPosition();
      shipForward = spt->getPlayerShip()->getPhysicsObject().getForward();
      shipUp = spt->getPlayerShip()->getPhysicsObject().getUp();
    }
    calculateCameraPosition();
    gluLookAt(cameraPosition.getX(), cameraPosition.getY(), cameraPosition.getZ(),
              shipPosition.getX(), shipPosition.getY(), shipPosition.getZ(),
              shipUp.getX(), shipUp.getY(), shipUp.getZ());
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

void PlayableState::calculateCameraPosition()
{
    cameraPosition.setX(shipPosition.getX() + (shipForward.getX() * -cameraDistance) + (shipUp.getX() * cameraHeight));
    cameraPosition.setY(shipPosition.getY() + (shipForward.getY() * -cameraDistance) + (shipUp.getY() * cameraHeight));
    cameraPosition.setZ(shipPosition.getZ() + (shipForward.getZ() * -cameraDistance) + (shipUp.getZ() * cameraHeight));
}

double PlayableState::degreeToRadian(double degree)
{
  return degree * M_PI / 180.0;
}

double PlayableState::radianToDegree(double radian)
{
  return radian * 180.0 / M_PI;
}
