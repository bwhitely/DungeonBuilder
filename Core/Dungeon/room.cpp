#include "room.h"
#include <iostream>

namespace core::dungeon {

Room::Room(const int id): _id{id}, _item{"No Name Item"}, _creature{"No Name Creature"}, _north{nullptr}, _east{nullptr}, _south{nullptr}, _west{nullptr}
{

}

Room::~Room(){
    // set ptrs to null
    _north = nullptr;
    _south = nullptr;
    _west = nullptr;
    _east = nullptr;
}

std::vector<std::string> Room::display()
{


}

int Room::id() const
{

}

items::Item Room::item()
{
    return _item;
}

void Room::setItem(items::Item newItem)
{
    _item = newItem;
}

AbstractCreature Room::creature()
{
    return _creature;
}

void Room::setCreature(AbstractCreature &newCreature)
{
    _creature = newCreature;
}

void Room::setNorth(RoomEdge* edge)
{
    _north = edge;
}

const RoomEdge *Room::getNorth() const
{
    return _north;
}

void Room::setEast(RoomEdge* edge)
{
    _east = edge;
}

const RoomEdge *Room::getEast() const
{
    return _east;
}

void Room::setSouth(RoomEdge* edge)
{
    _south = edge;
}

const RoomEdge *Room::getSouth() const
{
    return _south;
}

void Room::setWest(RoomEdge* edge)
{
    _west = edge;
}

const RoomEdge *Room::getWest() const
{
    return _west;
}

std::ostream& operator<<(std::ostream &out, const Room &room)
{
    return out << room.description();
}

}
