#include "lockeddoor.h"
#include <iostream>

namespace core::dungeon::common{

LockedDoor::LockedDoor(Direction direction): Doorway{direction} {
}

LockedDoor::~LockedDoor()
{
    std::cout << "Deleting LockedDoor";
}

void LockedDoor::connect(Doorway *opposite)
{
    _opposite = opposite;
}

bool LockedDoor::isEntrance()
{
    return false;
}

bool LockedDoor::isExit()
{
    return false;
}

bool LockedDoor::isPassage() const
{

}

char LockedDoor::displayCharacter() const
{

}

std::string LockedDoor::description() const
{
    return "Locked Door";
}

}

