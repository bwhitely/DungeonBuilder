#include "blockeddoorway.h"
#include <iostream>

namespace core::dungeon::common{

BlockedDoorWay::BlockedDoorWay(Direction direction): Doorway{direction} {

}

BlockedDoorWay::~BlockedDoorWay()
{
    if (_opposite)
        _opposite = nullptr;
    std::cout << "Deleting BlockedDoorWay";
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
    return "Blocked Door Way";
}

}

