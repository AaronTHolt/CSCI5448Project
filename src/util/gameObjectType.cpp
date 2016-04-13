#include "gameObjectType.h"

#include <string>

std::ostream& operator<<(std::ostream& os, GameObjectType const & got){
  std::string output = "";
  switch(got){
  case GameObjectType::Asteroid:
    output = "Asteroid";
    break;
  case GameObjectType::Ship:
    output = "Ship";
    break;
  case GameObjectType::Boundary:
    output = "Boundary";
    break;
  case GameObjectType::Projectile:
    output = "Projectile";
    break;
  default:
    output = "Unknown Type";
    break;
  }

  os << output;
  return os;
}
