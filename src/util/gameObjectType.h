#ifndef _GAME_OBJECT_TYPE_H_
#define _GAME_OBJECT_TYPE_H_

#include <iostream>

enum class GameObjectType {
    Asteroid,
    Ship,
    Boundary,
    Projectile,
};

std::ostream& operator<<(std::ostream& os, GameObjectType const & got);

#endif
