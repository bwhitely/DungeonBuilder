#include "blockeddoorway.h"
#include <iostream>

namespace core::dungeon::common {

BlockedDoorWay::BlockedDoorWay(Direction direction): Doorway{direction} {
    _direction = direction;

}

/**
 * @brief BlockedDoorWay::~BlockedDoorWay
 * Sets _opposite doorway to nullptr
 */
BlockedDoorWay::~BlockedDoorWay() {
    // remove dangling ptr
    if (_opposite)
        _opposite = nullptr;
}

/**
 * @brief BlockedDoorWay::connect - Connects to opposite doorway via bare pointer
 * @param opposite
 */
void BlockedDoorWay::connect(Doorway* opposite) {
    if (_opposite == nullptr){
    // connecting via bare pointer
        _opposite = opposite;
        opposite->connect(this);
    }
}

/**
 * @brief BlockedDoorWay::isEntrance
 * @return false
 */
bool BlockedDoorWay::isEntrance()
{
    return false;
}


/**
 * @brief BlockedDoorWay::isExit
 * @return false
 */
bool BlockedDoorWay::isExit()
{
    return false;
}

/**
 * @brief BlockedDoorWay::isPassage
 * @return false
 */
bool BlockedDoorWay::isPassage() const {
    return false;
}

/**
 * @brief BlockedDoorWay::displayCharacter
 * @return 'X'
 */
char BlockedDoorWay::displayCharacter() const {
    return 'X';
}

/**
 * @brief BlockedDoorWay::description
 * @return returns one line description of Doorway
 */
std::string BlockedDoorWay::description() const {
    return "a Blocked Doorway to another chamber";
}

}

