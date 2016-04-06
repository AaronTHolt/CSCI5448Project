#ifndef _PLAYER_SHIP_CONTROLS_H_
#define _PLAYER_SHIP_CONTROLS_H_

#include <Qt>
#include <QKeyEvent>

#include "shipControls.h"

class PlayerShipControls : public ShipControls{
 public:
  PlayerShipControls(Ship s);
  
  void onKeyPressed(QKeyEvent* event);

};

#endif
