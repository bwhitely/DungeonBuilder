#include "opendoorway.h"
#include <iostream>
namespace core::dungeon::common {

OpenDoorway::OpenDoorway(Direction direction): Doorway{direction} {
    _direction = direction;
}

OpenDoorway::~OpenDoorway() {
    if (_opposite)
        _opposite = nullptr;

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
    // if opposite is an opendoorway then it's a passage
    if (OpenDoorway* b = dynamic_cast<OpenDoorway*>(_opposite)){
        // delete pointer object
        delete b;
        return true;
    } else {
        return false;
    }
}

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

std::string OpenDoorway::description() const {
    return "Open Doorway";
}


}

