#include "basicdungeonlevel.h"

namespace core::dungeon::basic{

BasicDungeonLevel::BasicDungeonLevel(std::string name, int width, int height) : DungeonLevel(name, width, height)
{
    _name = name;
    _width = width;
    _height = height;
}

std::string BasicDungeonLevel::description()
{
    return "Description of BasicDungeonLevel";
}

bool BasicDungeonLevel::addRoom(Room *room)
{
    // add room to vector
    _rooms.push_back(room);
}

Room* BasicDungeonLevel::retrieveRoom(int i)
{
    return _rooms.at(i);
}

int BasicDungeonLevel::width()
{
    return _width;
}

int BasicDungeonLevel::height()
{
    return _height;
}

int BasicDungeonLevel::numberOfRooms()
{
    return _rooms.size();
}

std::string BasicDungeonLevel::name()
{
    return _name;
}

std::vector<std::string> BasicDungeonLevel::display()
{

}

}


