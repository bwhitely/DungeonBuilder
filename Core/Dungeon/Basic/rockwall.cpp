#include "rockwall.h"
#include <iostream>

namespace core::dungeon::basic {

RockWall::RockWall(Direction direction): Wall{direction} {

}

RockWall::~RockWall() {
    std::cout << "Destroying wall\n";
}

bool RockWall::isPassage() const {

}

char RockWall::displayCharacter() const {

}

std::string RockWall::description() const {
    return "Rock Wall";
}

void RockWall::printDirection() {
    std::cout << _direction << std::endl;
}
}
