#include "blockeddoorway.h"
#include <iostream>

namespace core::dungeon::common{

BlockedDoorWay::BlockedDoorWay(Direction direction): Doorway{direction} {
    _direction = direction;

}

BlockedDoorWay::~BlockedDoorWay()
{
    if (_opposite)
        _opposite = nullptr;
}

void BlockedDoorWay::connect(Doorway *opposite)
{
    _opposite = opposite;
}

bool BlockedDoorWay::isEntrance()
{
    return false;
}

bool BlockedDoorWay::isExit()
{
    return false;
}

bool BlockedDoorWay::isPassage() const
{
    return false;
}

char BlockedDoorWay::displayCharacter() const
{
    return 'X';
}

std::string BlockedDoorWay::description() const
{
    return "a Blocked Doorway to another chamber";
}

}

