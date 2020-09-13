#include "basicdungeonlevelbuilder.h"
#include <Core/Dungeon/Basic/rockchamber.h>
#include <Core/Dungeon/Common/opendoorway.h>
#include <Core/Creatures/abstractcreature.h>
#include <Core/Creatures/monster.h>
#include <Core/Dungeon/Basic/basicdungeonlevel.h>
#include <iostream>
#include <Core/Dungeon/Basic/rockwall.h>
#include <random>
#include <time.h>
#include <Core/Dungeon/Basic/quartzchamber.h>
#include <Core/Dungeon/Common/onewaydoor.h>

namespace core::dungeon::basic {

BasicDungeonLevelBuilder::BasicDungeonLevelBuilder() {

}

BasicDungeonLevelBuilder::~BasicDungeonLevelBuilder() {
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
    Room* r = nullptr;

    // level is null
    if (!level) {
        return nullptr;
        // level not null
    } else {
        if (randomInt() == 1) {
            r = new core::dungeon::basic::RockChamber(id);
            r->setNorth(new RockWall(Direction::North));
            r->setEast(new RockWall(Direction::East));
            r->setSouth(new RockWall(Direction::South));
            r->setWest(new RockWall(Direction::West));
            level->addRoom(r);

        } else if (randomInt() == 2) {
            r = new core::dungeon::basic::QuartzChamber(id);
            r->setNorth(new RockWall(Direction::North));
            r->setEast(new RockWall(Direction::East));
            r->setSouth(new RockWall(Direction::South));
            r->setWest(new RockWall(Direction::West));
            level->addRoom(r);

        }

        std::cout << "built room" << std::endl;

        return r;
    }
}

void BasicDungeonLevelBuilder::buildCreature(Room* room) {
    Monster* m = new Monster("Monster Name");
    room->setCreature(*m);
}

DungeonLevel* BasicDungeonLevelBuilder::getDungeonLevel() {
    return level;
}

void BasicDungeonLevelBuilder::buildExit(Room* room, Direction direction) {
    if (direction == Direction::North) {
        room->setNorth(new core::dungeon::common::OneWayDoor(Direction::North));
    } else if (direction == Direction::East) {
        room->setEast(new core::dungeon::common::OneWayDoor(Direction::East));
    } else if (direction == Direction::South) {
        room->setSouth(new core::dungeon::common::OneWayDoor(Direction::South));
    } else if (direction == Direction::West) {
        room->setWest(new core::dungeon::common::OneWayDoor(Direction::West));
    }
}

void BasicDungeonLevelBuilder::buildEntrance(Room* room, Direction direction) {
    if (direction == Direction::North) {
        room->setNorth(new core::dungeon::common::OneWayDoor(direction));
    } else if (direction == Direction::East) {
        room->setEast(new core::dungeon::common::OneWayDoor(direction));
    } else if (direction == Direction::South) {
        room->setSouth(new core::dungeon::common::OneWayDoor(direction));
    } else if (direction == Direction::West) {
        room->setWest(new core::dungeon::common::OneWayDoor(direction));
    }
}

void BasicDungeonLevelBuilder::buildDoorway(Room* origin, Room* destination, Direction direction, MoveConstraints constraints) {
    if (direction == Direction::North) {
        origin->setNorth(new core::dungeon::common::OpenDoorway(direction));
        destination->setSouth(new core::dungeon::common::OpenDoorway(direction));

    } else if (direction == Direction::East) {
        origin->setEast(new core::dungeon::common::OpenDoorway(direction));
        destination->setWest(new core::dungeon::common::OpenDoorway(direction));

    } else if (direction == Direction::South) {
        origin->setSouth(new core::dungeon::common::OpenDoorway(direction));
        origin->setNorth(new core::dungeon::common::OpenDoorway(direction));

    } else if (direction == Direction::West) {
        origin->setWest(new core::dungeon::common::OpenDoorway(direction));
        origin->setEast(new core::dungeon::common::OpenDoorway(direction));

    }
}

int BasicDungeonLevelBuilder::randomInt() {
    // random int between 1 and 2
    srand(time(NULL));
    return rand() % 2;
}

}
