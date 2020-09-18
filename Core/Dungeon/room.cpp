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
    _creature = nullptr;
    _item = nullptr;
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
        {'+', '-', '-', '-', _north->displayCharacter(), '-', '-', '-', '-', '+', ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' '},
        {_west->displayCharacter(), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', _east->displayCharacter(), ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' '},
        {'+', '-', '-', '-', _south->displayCharacter(), '-', '-', '-', '-', '+', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    // if Rooms south edge is NOT a rockwall it must be a Doorway, so add a pipeline to connect the doorways
    if (core::dungeon::basic::RockWall* r = dynamic_cast<basic::RockWall*>(_south)) {
        // Not an exit
    } else if (_south->displayCharacter() != 'O'){
        room.at(5).at(4) = '|';
    }
    // If Rooms east edge is NOT a rockkwall, it must be a Doorway, so add two dashes to connect the doorways
    if (core::dungeon::basic::RockWall* r = dynamic_cast<basic::RockWall*>(_east)) {

    } else if (_east->displayCharacter() != 'O' && _east->displayCharacter() != 'I'){
        room.at(2).at(10) = '-';
        room.at(2).at(11) = '-';
    }

    if (_item) {
        room.at(2).at(6) = item().displayCharacter();
    }

    if (_creature) {
        room.at(2).at(4) = 'M';
        if (_creature->isBoss()){
            room.at(2).at(5) = '*';
        }
    }
    return room;
}

int Room::id() const {
    return _id;
}

items::Item &Room::item() const
{
    return *_item;
}

void Room::setItem(std::unique_ptr<items::Item> newItem)
{
    _item = std::move(newItem);
}

AbstractCreature& Room::creature() const {
    return *_creature;
}

void Room::setCreature(std::unique_ptr<AbstractCreature> newCreature) {
    _creature = std::move(newCreature);
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

int Room::numberOfEdges()
{
    int num = 0;
    if (Doorway* r = dynamic_cast<Doorway*>(_south))
        num++;
    if (Doorway* r = dynamic_cast<Doorway*>(_north))
        num++;
    if (Doorway* r = dynamic_cast<Doorway*>(_east))
        num++;
    if (Doorway* r = dynamic_cast<Doorway*>(_west))
        num++;
    return num;
}

std::ostream& operator<<(std::ostream& out, const Room& room) {
    return out << room.description();
}

}
