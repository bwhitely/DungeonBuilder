#include "dungeonlevel.h"

namespace core::dungeon {

DungeonLevel::~DungeonLevel()
{

}

DungeonLevel::DungeonLevel(std::string name, int width, int height)
{

}

bool DungeonLevel::addRoom(Room *room)
{
    _rooms.push_back(room);
}

Room *DungeonLevel::retrieveRoom(int id)
{
    return _rooms.at(id);
}

int DungeonLevel::width() const
{

}

int DungeonLevel::height() const
{

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

