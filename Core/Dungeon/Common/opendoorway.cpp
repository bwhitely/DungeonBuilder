#include "opendoorway.h"
#include <iostream>
namespace core::dungeon::common {

OpenDoorway::OpenDoorway(Direction direction): Doorway{direction} {
}

OpenDoorway::~OpenDoorway() {
    std::cout << "Deleting Opendoorway";
}

void OpenDoorway::connect(Doorway* opposite) {
    // connecting via bare pointer
    _opposite = opposite;
}

bool OpenDoorway::isEntrance() {
    return false;
}

bool OpenDoorway::isExit() {
    return false;
}

bool OpenDoorway::isPassage() const {

}

char OpenDoorway::displayCharacter() const {
    if (_entrance){
        return 'I';
    }
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

std::string OpenDoorway::description() const {
    return "Open Doorway";
}


}

