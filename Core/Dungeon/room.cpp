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
#include <Core/Dungeon/Magical/magicwall.h>

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
    std::cout << "destroyed room" << std::endl;
}

std::vector<std::string> Room::display() {
    // 12 x 6 matrix
    std::vector<std::string> room = {
        {'+', '-', '-', '-', _north->displayCharacter(), '-', '-', '-', '-', '+', ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' '},
        {_west->displayCharacter(), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', _east->displayCharacter(), ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' '},
        {'+', '-', '-', '-', _south->displayCharacter(), '-', '-', '-', '-', '+', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    // if Rooms south edge is NOT a RockWall or MagicWall, it must be a Doorway, so add a pipeline to connect the doorways
    if (core::dungeon::basic::RockWall* r = dynamic_cast<basic::RockWall*>(_south)) {
        // Not an exit
    } else if (core::dungeon::magical::MagicWall* m = dynamic_cast<magical::MagicWall*>(_south)) {
        // do nothing
        // Not an exit (can't be an entrance on south side), add a pipeline to connect
    } else if (_south->displayCharacter() != 'O'){
        room.at(5).at(4) = '|';
    }
    // If Rooms east edge is NOT a RockWall or MagicWall it must be a Doorway, so add two dashes to connect the doorways
    if (core::dungeon::basic::RockWall* r = dynamic_cast<basic::RockWall*>(_east)) {
        // do nothing
    } else if (core::dungeon::magical::MagicWall* m = dynamic_cast<magical::MagicWall*>(_east)) {
        // do nothing
    // Doorway is NOT an exit or entrance, add hyphens to connect
    } else if (_east->displayCharacter() != 'O' && _east->displayCharacter() != 'I'){
        room.at(2).at(10) = '-';
        room.at(2).at(11) = '-';
    }

    // Add item character
    if (_item) {
        room.at(2).at(6) = item().displayCharacter();
    }
    // Add creature character
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
    // Move pointer to new item
    _item = std::move(newItem);
}

AbstractCreature& Room::creature() const {
    return *_creature;
}

void Room::setCreature(std::unique_ptr<AbstractCreature> newCreature) {
    // Move pointer to new creature
    _creature = std::move(newCreature);
}

void Room::setNorth(RoomEdge* edge) {
    _north = edge;
}

RoomEdge* Room::getNorth() const {
    return _north;
}

void Room::setEast(RoomEdge* edge) {
    _east = edge;
}

RoomEdge* Room::getEast() const {
    return _east;
}

void Room::setSouth(RoomEdge* edge){
    _south = edge;
}

RoomEdge* Room::getSouth() const {
    return _south;
}

void Room::setWest(RoomEdge* edge) {
    _west = edge;
}

RoomEdge* Room::getWest() const {
    return _west;
}

void Room::setEdge(Direction direction, std::string dwayType)
{
    // Used for dungeon builder. Sets doorway type and direction depending on parameters
    if (dwayType == "open"){
        if (direction == North)
            setNorth(new core::dungeon::common::OpenDoorway(direction));
        else if (direction == South)
            setSouth(new core::dungeon::common::OpenDoorway(direction));
        else if (direction == East)
            setEast(new core::dungeon::common::OpenDoorway(direction));
        else if (direction == West)
            setWest(new core::dungeon::common::OpenDoorway(direction));
    }
    else if (dwayType == "oneway"){
        if (direction == North)
            setNorth(new core::dungeon::common::OneWayDoor(direction, false, false));
        else if (direction == South)
            setSouth(new core::dungeon::common::OneWayDoor(direction, false, false));
        else if (direction == East)
            setEast(new core::dungeon::common::OneWayDoor(direction, false, false));
        else if (direction == West)
            setWest(new core::dungeon::common::OneWayDoor(direction, false, false));
    }
    else if (dwayType == "locked"){
        if (direction == North)
            setNorth(new core::dungeon::common::LockedDoor(direction));
        else if (direction == South)
            setSouth(new core::dungeon::common::LockedDoor(direction));
        else if (direction == East)
            setEast(new core::dungeon::common::LockedDoor(direction));
        else if (direction == West)
            setWest(new core::dungeon::common::LockedDoor(direction));
    }
    else if (dwayType == "blocked"){
        if (direction == North)
            setNorth(new core::dungeon::common::BlockedDoorWay(direction));
        else if (direction == South)
            setSouth(new core::dungeon::common::BlockedDoorWay(direction));
        else if (direction == East)
            setEast(new core::dungeon::common::BlockedDoorWay(direction));
        else if (direction == West)
            setWest(new core::dungeon::common::BlockedDoorWay(direction));
    }
}

RoomEdge* Room::getEdge(Direction direction) const
{
    // Returns Room edge depending on direction parameter
    if (direction == North)
        return getNorth();
    else if (direction == South)
        return getSouth();
    else if (direction == East)
        return getEast();
    else if (direction == West)
        return getWest();
}

int Room::numberOfEdges()
{
    // Returns number Doorways
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

bool Room::hasCreature()
{
    // Returns true if creature exists
    if (_creature != nullptr)
        return true;
    else
        return false;
}

bool Room::hasItem()
{
    // Returns true if item exists
    if (_item != nullptr)
        return true;
    else
        return false;
}

bool Room::containsExit()
{
    // If a RoomEdge has the character 'O', it must be an exit
    if (_west->displayCharacter() == 'O' || _east->displayCharacter() == 'O' || _south->displayCharacter() == 'O' || _north->displayCharacter() == 'O')
        return true;
    else
        return false;
}

bool Room::containsEntrance()
{
    // If a RoomEdge has the character 'I', it must be an entrance
    if (_west->displayCharacter() == 'I' || _east->displayCharacter() == 'I' || _south->displayCharacter() == 'I' || _north->displayCharacter() == 'I')
        return true;
    else
        return false;
}

// Overloaded operator
std::ostream& operator<<(std::ostream& out, const Room& room) {
    return out << room.description();
}

}
