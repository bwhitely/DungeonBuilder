#include "room.h"
#include <iostream>
#include "Common/opendoorway.h"
#include <Core/Dungeon/Common/onewaydoor.h>
#include <Core/Dungeon/Common/opendoorway.h>
#include <Core/Dungeon/Common/lockeddoor.h>
#include <Core/Dungeon/Common/blockeddoorway.h>
#include <Core/Dungeon/Basic/rockwall.h>
#include <Core/Creatures/abstractcreature.h>
#include <Core/Creatures/monster.h>

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
    std::vector<std::string> room = {
        {'+', '-', '-', '-', this->getNorth()->displayCharacter(), '-', '-', '-', '-', '+', ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' '},
        {this->getWest()->displayCharacter(), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', this->getEast()->displayCharacter(), ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' '},
        {'+', '-', '-', '-', this->getSouth()->displayCharacter(), '-', '-', '-', '-', '+', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    // if Rooms southedge is NOT a rockwall it must be a Doorway, so add a pipeline to connect the rooms
    if (core::dungeon::basic::RockWall* r = dynamic_cast<basic::RockWall*>(this->getSouth())) {

    } else {
        room.at(5).at(4) = '|';
    }

    if (core::dungeon::basic::RockWall* r = dynamic_cast<basic::RockWall*>(this->getEast())) {

    } else {
        room.at(2).at(10) = '-';
        room.at(2).at(11) = '-';
    }

    if (_item) {
        room.at(2).at(6) = item()->displayCharacter();
    }

    if (_creature) {
        room.at(2).at(4) = 'M';
//        if (_creature->isBoss()){
//            room.at(2).at(5) = '*';
//        }
    }
    return room;
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

RoomEdge* Room::getNorth() {
    return _north;
}

void Room::setEast(RoomEdge* edge) {
    _east = edge;
}

RoomEdge* Room::getEast() {
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

RoomEdge* Room::getWest() {
    return _west;
}

std::ostream& operator<<(std::ostream& out, const Room& room) {
    return out << room.description();
}

}
