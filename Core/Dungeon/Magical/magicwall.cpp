#include "magicwall.h"
#include <iostream>

namespace core::dungeon::magical {

MagicWall::MagicWall(Direction direction): Wall{direction} {
    _direction = direction;
}

MagicWall::~MagicWall() {
    std::cout << "Destroying magic wall\n";
}

bool MagicWall::isPassage() const {
    return false;
}

char MagicWall::displayCharacter() const {
    if (_direction == North || _direction == South)
        return '-';
    else if (_direction == East || _direction == West)
        return '|';
}

std::string MagicWall::description() const {
    return "Magic Wall";
}

void MagicWall::printDirection() {
    std::cout << _direction;
}

}

