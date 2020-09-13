#include "blockeddoorway.h"
#include <iostream>

namespace core::dungeon::common{

BlockedDoorWay::BlockedDoorWay(Direction direction): Doorway{direction} {

}

BlockedDoorWay::~BlockedDoorWay()
{
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

}

char BlockedDoorWay::displayCharacter() const
{

}

std::string BlockedDoorWay::description() const
{
    return "Blocked Door Way";
}

}

