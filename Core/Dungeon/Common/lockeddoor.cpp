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
    // set to nullptr
    if (_opposite)
        _opposite = nullptr;
        std::cout << "destroyed doorway" <<std::endl;
}

/**
 * @brief LockedDoor::connect - Connects to opposite Doorway via bare pointer
 * @param opposite
 */
void LockedDoor::connect(Doorway* opposite) {
    if (_opposite == nullptr){
    // connecting via bare pointer
        _opposite = opposite;
        opposite->connect(this);
    }
}

/**
 * @brief LockedDoor::isEntrance
 * @return false
 */
bool LockedDoor::isEntrance() {
    return false;
}

/**
 * @brief LockedDoor::isExit
 * @return false
 */
bool LockedDoor::isExit() {
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

