#ifndef _SHIP_CONTROLS_H_
#define _SHIP_CONTROLS_H_

#include "ship.h"

class ShipControls{
 public:
  ShipControls(Ship* ship);
  virtual void doEvents() = 0;
 protected:
  Ship* ship;
};

#endif
