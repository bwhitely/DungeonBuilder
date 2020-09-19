#include "onewaydoor.h"
#include <iostream>

namespace core::dungeon::common{

OneWayDoor::OneWayDoor(Direction direction, bool entrance, bool exit): Doorway{direction} {
    _direction = direction;
    _entrance = entrance;
    _exit = exit;
}

OneWayDoor::~OneWayDoor()
{
    if (_opposite)
        _opposite = nullptr;
}

void OneWayDoor::connect(Doorway *opposite)
{
    _opposite = opposite;
}

bool OneWayDoor::isEntrance()
{
    if (_entrance)
        return true;
    else
        return false;
}

bool OneWayDoor::isExit()
{
    if (_exit)
        return true;
    else
        return false;
}

bool OneWayDoor::isPassage() const
{
    return true;
}

char OneWayDoor::displayCharacter() const
{
    if (_entrance){
        return 'I';
    } else if (_exit){
        return 'O';

    } if (_direction == North){
        return '^';
    } else if (_direction == East){
        return '>';
    } else if (_direction == South){
        return 'v';
    } else if (_direction == West){
        return '<';
    }
}

std::string OneWayDoor::description() const
{
    if (_entrance){
        return "The entrance to the dungeon level.";
    } else if (_exit) {
        return "The exit from the dungeon level.";
    } else {
        return "a One Way Door to another chamber";
    }
}
}

