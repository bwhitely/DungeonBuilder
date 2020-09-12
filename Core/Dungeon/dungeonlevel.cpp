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

}

Room *DungeonLevel::retrieveRoom(int id)
{
    return _rooms.at(1);
}

int DungeonLevel::width() const
{

}

int DungeonLevel::height() const
{

}

int DungeonLevel::numberOfRooms() const
{

}

std::string DungeonLevel::name() const
{
    return _name;
}

std::vector<std::string> DungeonLevel::display()
{
    Room* r = _rooms.at(1);
    r->display();
}

}

