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
    _rooms.push_back(room);
    return true;
}

Room *DungeonLevel::retrieveRoom(int id)
{
    return _rooms.at(id-1);
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
    Room* r = _rooms.at(0);
    r->display();
}

}

