#include "onewaydoor.h"
#include <iostream>

namespace core::dungeon::common{

OneWayDoor::OneWayDoor(Direction direction): Doorway{direction} {
}

OneWayDoor::~OneWayDoor()
{
    std::cout << "Deleting OneWayDoor";
}

void OneWayDoor::connect(Doorway *opposite)
{
    _opposite = opposite;
}

bool OneWayDoor::isEntrance()
{

}

bool OneWayDoor::isExit()
{

}

bool OneWayDoor::isPassage() const
{
    return true;
}

char OneWayDoor::displayCharacter() const
{

}

std::string OneWayDoor::description() const
{
    return "One Way Door";
}

}

