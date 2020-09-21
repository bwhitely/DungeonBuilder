#include "rockwall.h"
#include <iostream>

namespace core::dungeon::basic {

RockWall::RockWall(Direction direction): Wall{direction} {
    _direction = direction;
}

RockWall::~RockWall() {

}

/**
 * @brief RockWall::isPassage
 * @return false
 */
bool RockWall::isPassage() const {
    return false;
}

/**
 * @brief RockWall::displayCharacter - Returns char representation, varies depending on RoomEdge direction
 * @return
 */
char RockWall::displayCharacter() const {
    if (_direction == North || _direction == South)
        return '-';
    else if (_direction == East || _direction == West)
        return '|';
}

/**
 * @brief RockWall::description
 * @return std::string simple description of type of Wall
 */
std::string RockWall::description() const {
    return "a Rock Wall";
}

void RockWall::printDirection() const {
    std::cout << _direction << std::endl;
}
}
