#include "room.h"

namespace core::dungeon {

Room::Room(const int id): _id{id}, _item{}, _creature{}, _north{nullptr}, _east{nullptr}, _south{nullptr}, _west{nullptr}
{

}

Room::~Room(){

}

std::vector<std::string> Room::display() const
{

}

int Room::id() const
{

}

items::Item &Room::item() const
{

}

void Room::setItem(items::Item &newItem)
{

}

AbstractCreature &Room::creature() const
{

}

void Room::setCreature(AbstractCreature &newCreature)
{

}

void Room::setNorth(RoomEdge* edge)
{
    _north = edge;
}

const RoomEdge &Room::getNorth() const
{

}

void Room::setEast(RoomEdge* edge)
{
    _east = edge;
}

const RoomEdge &Room::getEast() const
{

}

void Room::setSouth(RoomEdge* edge)
{
    _south = edge;
}

const RoomEdge &Room::getSouth() const
{

}

void Room::setWest(RoomEdge* edge)
{
    _west = edge;
}

const RoomEdge &Room::getWest() const
{

}

std::ostream& operator<<(std::ostream &out, const Room &room)
{
    return out << room.description();
}

}
