#include "opendoorway.h"
#include <iostream>

namespace core::dungeon::common {

OpenDoorway::OpenDoorway(Direction direction): Doorway{direction} {
    _direction = direction;
}

/**
 * @brief OpenDoorway::~OpenDoorway
 * sets _opposite to nullptr
 */
OpenDoorway::~OpenDoorway() {
    // remove dangling ptr
    if (_opposite)
        _opposite = nullptr;
        std::cout << "destroyed doorway" <<std::endl;
}

/**
 * @brief OpenDoorway::connect - Connects to opposite doorway via bare pointer
 * @param opposite
 */
void OpenDoorway::connect(Doorway* opposite) {
    if (_opposite == nullptr){
    // connecting via bare pointer
        _opposite = opposite;
        opposite->connect(this);
    }
}

/**
 * @brief OpenDoorway::isEntrance
 * @return false
 */
bool OpenDoorway::isEntrance() {
    return false;
}

/**
 * @brief OpenDoorway::isExit
 * @return false
 */
bool OpenDoorway::isExit() {
    return false;
}
/**
 * @brief OpenDoorway::isPassage
 * @return true
 */
bool OpenDoorway::isPassage() const {
    // if opposite is an opendoorway then it's a passage
    if (OpenDoorway* b = dynamic_cast<OpenDoorway*>(_opposite)) {
        // delete pointer object
        delete b;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief OpenDoorway::displayCharacter
 * @return '^', 'v', '>', '<' depending on Direction
 */
char OpenDoorway::displayCharacter() const {

    if(_direction == North) {
        return '^';
    } else if (_direction == East) {
        return '>';
    } else if (_direction == South) {
        return 'v';
    } else if (_direction == West) {
        return '<';
    }
}

/**
 * @brief OpenDoorway::description
 * @return std::string description of Doorway type
 */
std::string OpenDoorway::description() const {
    return "an Open Doorway to another chamber";
}


}

