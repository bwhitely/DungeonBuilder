#include "lockeddoor.h"
#include <iostream>

namespace core::dungeon::common{

LockedDoor::LockedDoor(Direction direction): Doorway{direction} {
    _direction = direction;
}

LockedDoor::~LockedDoor()
{
    // remove dangling ptr
    if (_opposite)
        _opposite = nullptr;
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
    return false;
}

char LockedDoor::displayCharacter() const
{
    return '@';
}

std::string LockedDoor::description() const
{
    return "a Locked Door to another chamber";
}

}

