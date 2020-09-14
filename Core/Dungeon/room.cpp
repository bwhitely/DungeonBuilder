#include "room.h"
#include <iostream>

namespace core::dungeon {

Room::Room(const int id): _id{id}, _north{nullptr}, _east{nullptr}, _south{nullptr}, _west{nullptr} {

}

Room::~Room() {
    // set ptrs to null
    _north = nullptr;
    _south = nullptr;
    _west = nullptr;
    _east = nullptr;
    _item = nullptr;
    _creature = nullptr;
}

std::vector<std::string> Room::display() {

}

int Room::id() const {
    return _id;
}

items::Item* Room::item() {
    return _item;
}

void Room::setItem(items::Item* newItem) {
    _item = newItem;
}

AbstractCreature* Room::creature() {
    return _creature;
}

void Room::setCreature(AbstractCreature* newCreature) {
    _creature = newCreature;
}

void Room::setNorth(RoomEdge* edge) {
    _north = edge;
}

RoomEdge* Room::getNorth(){
    return _north;
}

void Room::setEast(RoomEdge* edge) {
    _east = edge;
}

RoomEdge* Room::getEast(){
    return _east;
}

void Room::setSouth(RoomEdge* edge) {
    _south = edge;
}

RoomEdge* Room::getSouth() {
    return _south;
}

void Room::setWest(RoomEdge* edge) {
    _west = edge;
}

RoomEdge* Room::getWest(){
    return _west;
}

std::ostream& operator<<(std::ostream& out, const Room& room) {
    return out << room.description();
}

}
