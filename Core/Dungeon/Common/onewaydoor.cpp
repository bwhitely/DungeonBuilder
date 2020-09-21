#include "onewaydoor.h"
#include <iostream>

namespace core::dungeon::common {

OneWayDoor::OneWayDoor(Direction direction, bool entrance, bool exit): Doorway{direction} {
    _direction = direction;
    _entrance = entrance;
    _exit = exit;
}

/**
 * @brief OneWayDoor::~OneWayDoor
 * Sets _opposite to nullptr
 */
OneWayDoor::~OneWayDoor() {
    // remove dangling ptr
    if (_opposite)
        _opposite = nullptr;
    std::cout << "delete door" << std::endl;
}

/**
 * @brief OneWayDoor::connect - Connects to opposite doorway via bare pointer
 * @param opposite
 */
void OneWayDoor::connect(Doorway* opposite) {
    _opposite = opposite;
}

/**
 * @brief OneWayDoor::isEntrance
 * @return true if Doorway is entrance, false otherwise
 */
bool OneWayDoor::isEntrance() const {
    if (_entrance)
        return true;
    else
        return false;
}

/**
 * @brief OneWayDoor::isExit
 * @return true if Doorway is exit, false otherwise
 */
bool OneWayDoor::isExit() const {
    if (_exit)
        return true;
    else
        return false;
}

/**
 * @brief OneWayDoor::isPassage - Determines if Doorway is a passage (can pass through)
 * @return false if Doorway is exit or entrance, true otherwise
 */
bool OneWayDoor::isPassage() const {
    // exit/entrances can't be passages
    if (_exit || _entrance)
        return false;
    else
        return true;
}

/**
 * @brief OneWayDoor::displayCharacter
 * @return 'I' if entrance, 'O' if exit.
 * 'v', '^', '>', '<' depending on Direction
 */
char OneWayDoor::displayCharacter() const {
    if (_entrance) {
        return 'I';
    } else if (_exit) {
        return 'O';

    }

    if (_direction == North) {
        return 'v';
    } else if (_direction == East) {
        return '<';
    } else if (_direction == South) {
        return '^';
    } else if (_direction == West) {
        return '>';
    }
}

/**
 * @brief OneWayDoor::description
 * @return std::string description of Doorway, varies depending on exit/entrance/neither
 */
std::string OneWayDoor::description() const {
    if (_entrance) {
        return "The entrance to the dungeon level.";
    } else if (_exit) {
        return "The exit from the dungeon level.";
    } else {
        return "an One Way Door to another chamber";
    }
}
}

