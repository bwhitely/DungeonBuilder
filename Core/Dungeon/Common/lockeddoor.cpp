#include "lockeddoor.h"
#include <iostream>

namespace core::dungeon::common {

LockedDoor::LockedDoor(Direction direction): Doorway{direction} {
    _direction = direction;
}

/**
 * @brief LockedDoor::~LockedDoor
 * Sets _opposite to nullptr
 */
LockedDoor::~LockedDoor() {
    // remove dangling ptr
    if (_opposite)
        _opposite = nullptr;
}

/**
 * @brief LockedDoor::connect - Connects to opposite Doorway via bare pointer
 * @param opposite
 */
void LockedDoor::connect(Doorway* opposite) {
    _opposite = opposite;
}

/**
 * @brief LockedDoor::isEntrance
 * @return false
 */
bool LockedDoor::isEntrance() const {
    return false;
}

/**
 * @brief LockedDoor::isExit
 * @return false
 */
bool LockedDoor::isExit() const {
    return false;
}

/**
 * @brief LockedDoor::isPassage
 * @return false
 */
bool LockedDoor::isPassage() const {
    return false;
}
/**
 * @brief LockedDoor::displayCharacter
 * @return '@'
 */
char LockedDoor::displayCharacter() const {
    return '@';
}

/**
 * @brief LockedDoor::description
 * @return one line description of Doorway type
 */
std::string LockedDoor::description() const {
    return "a Locked Door to another chamber";
}

}

