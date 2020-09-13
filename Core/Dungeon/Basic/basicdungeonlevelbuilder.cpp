#include "basicdungeonlevelbuilder.h"
#include <Core/Dungeon/Basic/rockchamber.h>
#include <Core/Dungeon/Common/opendoorway.h>
#include <Core/Creatures/abstractcreature.h>
#include <Core/Creatures/monster.h>
#include <Core/Dungeon/Basic/basicdungeonlevel.h>
#include <iostream>

namespace core::dungeon::basic {

BasicDungeonLevelBuilder::BasicDungeonLevelBuilder() {

}

BasicDungeonLevelBuilder::~BasicDungeonLevelBuilder()
{
    level = nullptr;
}

void BasicDungeonLevelBuilder::BuildDungeonLevel(std::string name, int width, int height) {
    level = new core::dungeon::basic::BasicDungeonLevel(name, width, height);
}

void BasicDungeonLevelBuilder::buildItem(Room* room) {
    core::items::Item* item = new core::items::Item("Cool Item");
    room->setItem(*item);
}

Room* BasicDungeonLevelBuilder::buildRoom(int id) {
    std::cout << "1" << std::endl;
    core::dungeon::basic::RockChamber* r = new core::dungeon::basic::RockChamber(id);
    std::cout << "2" << std::endl;
    r->setNorth(new core::dungeon::common::OpenDoorway(Direction::North, true, false));
    std::cout << "3" << std::endl;
    r->setEast(new core::dungeon::common::OpenDoorway(Direction::East, false, false));
    std::cout << "4" << std::endl;
    r->setSouth(new core::dungeon::common::OpenDoorway(Direction::South, false, false));
    std::cout << "5" << std::endl;
    r->setWest(new core::dungeon::common::OpenDoorway(Direction::West, false, false));
    std::cout << "6" << std::endl;

    level->addRoom(r);
    std::cout << "7" << std::endl;
    return r;
}

void BasicDungeonLevelBuilder::buildCreature(Room* room) {
    Monster* m = new Monster("Monster Name");
    room->setCreature(*m);
}

DungeonLevel* BasicDungeonLevelBuilder::getDungeonLevel() {
    return level;
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
