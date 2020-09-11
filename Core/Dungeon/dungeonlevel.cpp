#include "dungeonlevel.h"

namespace core::dungeon {

DungeonLevel::~DungeonLevel()
{

}

DungeonLevel::DungeonLevel(std::string name, int width, int height)
{
    _name = name;
    _width = width;
    _height = height;
}

bool DungeonLevel::addRoom(Room *room)
{
    // add room to vector
    _rooms.push_back(room);
}

Room *DungeonLevel::retrieveRoom(int id)
{
    return _rooms.at(id);
}

int DungeonLevel::width() const
{
    return _width;
}

int DungeonLevel::height() const
{
    return _height;
}

int DungeonLevel::numberOfRooms() const
{
    return _rooms.size();
}

std::string DungeonLevel::name() const
{
    return _name;
}

std::vector<std::string> DungeonLevel::display()
{

}

}

