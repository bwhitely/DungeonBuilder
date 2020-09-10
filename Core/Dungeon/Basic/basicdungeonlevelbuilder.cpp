#include "basicdungeonlevelbuilder.h"
#include <Core/Dungeon/Basic/rockchamber.h>
#include <Core/Dungeon/Common/opendoorway.h>
#include <Core/Creatures/abstractcreature.h>
#include <Core/Creatures/monster.h>

namespace core::dungeon::basic {

BasicDungeonLevelBuilder::BasicDungeonLevelBuilder() {

}

BasicDungeonLevelBuilder::~BasicDungeonLevelBuilder()
{

}

void BasicDungeonLevelBuilder::BuildDungeonLevel(std::string name, int width, int height) {
    _name = name;
    _width = width;
    _height = height;
}

void BasicDungeonLevelBuilder::buildItem(Room* room) {
    core::items::Item* item = new core::items::Item("Cool Item");
    room->setItem(*item);

}

Room* BasicDungeonLevelBuilder::buildRoom(int id) {
    core::dungeon::basic::RockChamber* r = new core::dungeon::basic::RockChamber(id);
    rooms.push_back(r);
    return r;
}

void BasicDungeonLevelBuilder::buildCreature(Room* room) {
    Monster* m = new Monster("asd");
    room->setCreature(*m);
}

DungeonLevel* BasicDungeonLevelBuilder::getDungeonLevel() {

}

void BasicDungeonLevelBuilder::buildExit(Room* room, Direction direction) {
    if (direction == Direction::North){
        room->setNorth(new core::dungeon::common::OpenDoorway(Direction::North, false, true));
    }
}

void BasicDungeonLevelBuilder::buildEntrance(Room* room, Direction direction) {
    if (direction == Direction::South){
        room->setSouth(new core::dungeon::common::OpenDoorway(Direction::South, true, false));
    }
}

void BasicDungeonLevelBuilder::buildDoorway(Room* origin, Room* destination, Direction direction, MoveConstraints constraints) {
    if (direction == Direction::North){
        origin->setNorth(new core::dungeon::common::OpenDoorway(direction, false, false));
        destination->setSouth(new core::dungeon::common::OpenDoorway(direction, false, false));

    } else if (direction == Direction::East){
        origin->setEast(new core::dungeon::common::OpenDoorway(direction, false, false));
        destination->setWest(new core::dungeon::common::OpenDoorway(direction, false ,false));

    } else if (direction == Direction::South){
        origin->setSouth(new core::dungeon::common::OpenDoorway(direction, false, false));
        origin->setNorth(new core::dungeon::common::OpenDoorway(direction, false ,false));

    } else if (direction == Direction::West){
        origin->setWest(new core::dungeon::common::OpenDoorway(direction, false, false));
        origin->setEast(new core::dungeon::common::OpenDoorway(direction, false, false));

    }
}
}
