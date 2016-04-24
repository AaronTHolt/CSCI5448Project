#ifndef _PLAYER_SHIP_CONTROLS_H_
#define _PLAYER_SHIP_CONTROLS_H_

#include <Qt>
#include <QKeyEvent>
#include <set>

#include "shipControls.h"

class PlayerShipControls : public ShipControls{
 public:
  PlayerShipControls(Ship* s);
  PlayerShipControls();

  void doEvents();
  
  void keyPressEvent(QKeyEvent* event);
  void keyReleaseEvent(QKeyEvent* event);

  std::set<int> keys;

};

#endif
