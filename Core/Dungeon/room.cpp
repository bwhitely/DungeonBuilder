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
    // delete Doorways and Walls
    delete _north;
    delete _south;
    delete _east;
    delete _west;
}

/**
 * @brief Room::display - Visual representation of an individual Room. Fills in vector with correct characters depending if room contains exit/entrance/item/creatures
 * @return std::vector<std::string>
 */
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
    } else if (_south->displayCharacter() != 'O') {
        room.at(5).at(4) = '|';
    }

    // If Rooms east edge is NOT a RockWall or MagicWall it must be a Doorway, so add two dashes to connect the doorways
    if (core::dungeon::basic::RockWall* r = dynamic_cast<basic::RockWall*>(_east)) {
        // do nothing
    } else if (core::dungeon::magical::MagicWall* m = dynamic_cast<magical::MagicWall*>(_east)) {
        // do nothing
        // Doorway is NOT an exit or entrance, add hyphens to connect
    } else if (_east->displayCharacter() != 'O' && _east->displayCharacter() != 'I') {
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

        if (_creature->isBoss()) {
            room.at(2).at(5) = '*';
        }
    }

    return room;
}

/**
 * @brief Room::id - id of Room
 * @return id
 */
int Room::id() const {
    return _id;
}

/**
 * @brief Room::item - Item inside room
 * @return Item reference
 */
items::Item& Room::item() const {
    return *_item;
}

/**
 * @brief Room::setItem - Adds unique_ptr of Item to room
 * @param newItem - Item to add
 */
void Room::setItem(std::unique_ptr<items::Item> newItem) {
    // Move pointer to new item
    _item = std::move(newItem);
}

/**
 * @brief Room::creature - Creature inside room
 * @return reference of creature in Room
 */
AbstractCreature& Room::creature() const {
    return *_creature;
}

/**
 * @brief Room::setCreature - Adds unique_ptr of Creature to room
 * @param newCreature - Creature to add
 */
void Room::setCreature(std::unique_ptr<AbstractCreature> newCreature) {
    // Move pointer to new creature
    _creature = std::move(newCreature);
}

/**
 * @brief Room::setNorth - Sets North edge of room to passed RoomEdge
 * @param edge
 */
void Room::setNorth(RoomEdge* edge) {
    _north = edge;
}

/**
 * @brief Room::getNorth
 * @return RoomEdge* on North side of Room
 */
RoomEdge* Room::getNorth() const {
    return _north;
}

/**
 * @brief Room::setNorth - Sets East edge of room to passed RoomEdge
 * @param edge
 */
void Room::setEast(RoomEdge* edge) {
    _east = edge;
}

/**
 * @brief Room::getEast
 * @return RoomEdge* on East side of Room
 */
RoomEdge* Room::getEast() const {
    return _east;
}

/**
 * @brief Room::setNorth - Sets South edge of room to passed RoomEdge
 * @param edge
 */
void Room::setSouth(RoomEdge* edge) {
    _south = edge;
}

/**
 * @brief Room::getSouth
 * @return RoomEdge* on South side of Room
 */
RoomEdge* Room::getSouth() const {
    return _south;
}

/**
 * @brief Room::setNorth - Sets West edge of room to passed RoomEdge
 * @param edge
 */
void Room::setWest(RoomEdge* edge) {
    _west = edge;
}

/**
 * @brief Room::getWest
 * @return RoomEdge* on South side of Room
 */
RoomEdge* Room::getWest() const {
    return _west;
}

/**
 * @brief Room::setEdge - Sets RoomEdge of Room, depending on direction on dwayType (type of Doorway).
 * Used in buildDoorway() in each type of DungeonBuilder.
 * @param direction
 * @param dwayType
 */
void Room::setEdge(Direction direction, std::string dwayType) {
    // Used for dungeon builder. Sets doorway type and direction depending on parameters
    if (dwayType == "open") {
        if (direction == North)
            setNorth(new core::dungeon::common::OpenDoorway(direction));
        else if (direction == South)
            setSouth(new core::dungeon::common::OpenDoorway(direction));
        else if (direction == East)
            setEast(new core::dungeon::common::OpenDoorway(direction));
        else if (direction == West)
            setWest(new core::dungeon::common::OpenDoorway(direction));
    } else if (dwayType == "oneway") {
        if (direction == North)
            setNorth(new core::dungeon::common::OneWayDoor(direction, false, false));
        else if (direction == South)
            setSouth(new core::dungeon::common::OneWayDoor(direction, false, false));
        else if (direction == East)
            setEast(new core::dungeon::common::OneWayDoor(direction, false, false));
        else if (direction == West)
            setWest(new core::dungeon::common::OneWayDoor(direction, false, false));
    } else if (dwayType == "locked") {
        if (direction == North)
            setNorth(new core::dungeon::common::LockedDoor(direction));
        else if (direction == South)
            setSouth(new core::dungeon::common::LockedDoor(direction));
        else if (direction == East)
            setEast(new core::dungeon::common::LockedDoor(direction));
        else if (direction == West)
            setWest(new core::dungeon::common::LockedDoor(direction));
    } else if (dwayType == "blocked") {
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

/**
 * @brief Room::getEdge - Gets edge in specified Direction
 * @param direction
 * @return RoomEdge*
 */
RoomEdge* Room::getEdge(Direction direction) const {
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

/**
 * @brief Room::numberOfEdges - Gets number of Doorways in a Room
 * @return int
 */
int Room::numberOfEdges() const {
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

/**
 * @brief Room::hasCreature - true if Room has a creature
 * @return bool
 */
bool Room::hasCreature() const {
    // Returns true if creature exists
    if (_creature != nullptr)
        return true;
    else
        return false;
}

/**
 * @brief Room::hasItem - true if Room has an Item
 * @return
 */
bool Room::hasItem() const {
    // Returns true if item exists
    if (_item != nullptr)
        return true;
    else
        return false;
}

/**
 * @brief Room::containsExit - true if Room contains exit on any RoomEdge
 * @return
 */
bool Room::containsExit() const {
    // If a RoomEdge has the character 'O', it must be an exit
    if (_west->displayCharacter() == 'O' || _east->displayCharacter() == 'O' || _south->displayCharacter() == 'O' || _north->displayCharacter() == 'O')
        return true;
    else
        return false;
}

/**
 * @brief Room::containsEntrance - true if Room contains Entrance on any RoomEdge
 * @return
 */
bool Room::containsEntrance() const {
    // If a RoomEdge has the character 'I', it must be an entrance
    if (_west->displayCharacter() == 'I' || _east->displayCharacter() == 'I' || _south->displayCharacter() == 'I' || _north->displayCharacter() == 'I')
        return true;
    else
        return false;
}

/**
 * @brief operator << - Overloaded << operator
 * @param out
 * @param room
 * @return
 */
std::ostream& operator<<(std::ostream& out, const std::shared_ptr<Room> room) {
    return out << room->description();
}

}
