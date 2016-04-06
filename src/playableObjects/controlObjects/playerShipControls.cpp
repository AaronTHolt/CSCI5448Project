#include "playerShipControls.h"

PlayerShipControls::PlayerShipControls(Ship* s):ShipControls(s) {}

void PlayerShipControls::onKeyPressed(QKeyEvent* event){
  const Qt::Key thrust = Qt::Key_W;
  const Qt::Key fire = Qt::Key_S;
  const Qt::Key pitchUp = Qt::Key_Up;
  const Qt::Key pitchDown = Qt::Key_Down;
  const Qt::Key yawLeft = Qt::Key_Left;
  const Qt::Key yawRight = Qt::Key_Right;

  
  switch(event->key()){
  case thrust:
    ship->thrust();
    break;
  case fire:
    ship->fireDefaultWeapon();
    break;
  case pitchUp:
    ship->pitch(true); // Pitch Up
    break;
  case pitchDown:
    ship->pitch(false); // Pitch Down
    break;
  case yawLeft:
    ship->yaw(false);
    break;
  case yawRight:
    ship->yaw(true);
  }
}
