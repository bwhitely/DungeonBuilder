#include "magicwall.h"
#include <iostream>

namespace core::dungeon::magical {

MagicWall::MagicWall(Direction direction): Wall{direction} {
    _direction = direction;
}

MagicWall::~MagicWall() {

}

/**
 * @brief MagicWall::isPassage
 * @return false
 */
bool MagicWall::isPassage() const {
    return false;
}

/**
 * @brief MagicWall::displayCharacter - '-' if Direction is North/South or '|' if Direction is East/West
 * @return char
 */
char MagicWall::displayCharacter() const {
    // Returns pipeline or hyphen depending on direction
    if (_direction == North || _direction == South)
        return '-';
    else if (_direction == East || _direction == West)
        return '|';
}

/**
 * @brief MagicWall::description - Short description of Magic Wall
 * @return std::string
 */
std::string MagicWall::description() const {
    return "Magic Wall";
}

void MagicWall::printDirection() const {
    std::cout << _direction;
}

}

