#include "rockwall.h"
#include <iostream>

namespace core::dungeon::basic {

RockWall::RockWall(Direction direction): Wall{direction} {
    _direction = direction;
}

RockWall::~RockWall() {
    std::cout << "Destroying wall\n";
}

bool RockWall::isPassage() const {
    return false;
}

char RockWall::displayCharacter() const {
    if (_direction == North || _direction == South)
        return '-';
    else if (_direction == East || _direction == West)
        return '|';
}

std::string RockWall::description() const {
    return "Rock Wall";
}

void RockWall::printDirection() {
    std::cout << _direction << std::endl;
}
}
