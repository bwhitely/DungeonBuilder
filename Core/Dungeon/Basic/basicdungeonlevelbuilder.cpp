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
#include <Core/Dungeon/Common/blockeddoorway.h>
#include <Core/Dungeon/Common/lockeddoor.h>

namespace core::dungeon::basic {

BasicDungeonLevelBuilder::BasicDungeonLevelBuilder() {
    srand(time(NULL));
    // add items to vectors
    items.push_back(std::unique_ptr<items::Item>(new core::items::Item("Health Potion")));
    items.push_back(std::unique_ptr<items::Item>(new core::items::Item("Molotov Cocktail")));
    items.push_back(std::unique_ptr<items::Item>(new core::items::Item("Smoke Bomb")));
    items.push_back(std::unique_ptr<items::Item>(new core::items::Item("Boomerang")));
    items.push_back(std::unique_ptr<items::Item>(new core::items::Item("Shord Sword")));
    items.push_back(std::unique_ptr<items::Item>(new core::items::Item("Battle Axe")));

    // add creatures to vectors
    creatures.push_back(new AbstractCreature("Goblin"));
    creatures.push_back(new AbstractCreature("Werewolf"));
    creatures.push_back(new AbstractCreature("Evil Wizard"));
}

BasicDungeonLevelBuilder::~BasicDungeonLevelBuilder() {
    // set level to null
    level = nullptr;

    // clear creature pointers
    for (AbstractCreature* c : creatures){
        delete c;
    }
    creatures.clear();
}

void BasicDungeonLevelBuilder::BuildDungeonLevel(std::string name, int width, int height) {
    level = new BasicDungeonLevel(name, width, height);
}

void BasicDungeonLevelBuilder::buildItem(Room* room) {

    int r = getRandomNumber(1, 6);

    // clone existing item into room
    if (r == 1)
        room->setItem(items.at(0)->clone());
     else if (r == 2)
        room->setItem(items.at(1)->clone());
     else if (r == 3)
        room->setItem(items.at(2)->clone());
     else if (r == 4)
        room->setItem(items.at(3)->clone());
     else if (r == 5)
        room->setItem(items.at(4)->clone());
     else if (r == 6)
        room->setItem(items.at(5)->clone());
}

void BasicDungeonLevelBuilder::buildCreature(Room* room) {
    int r = getRandomNumber(1, 3);

    // clone existing creature into room
    if (r == 1)
        room->setCreature(creatures.at(0)->clone());
     else if (r == 2)
        room->setCreature(creatures.at(1)->clone());
     else if (r == 3)
        room->setCreature(creatures.at(2)->clone());
}

Room* BasicDungeonLevelBuilder::buildRoom(int id) {
    // get int between 1 and 2
    int x = getRandomNumber(1, 2);
    Room* r = nullptr;

    // level is null
    if (!level) {
        return nullptr;
        // level not null
    } else {
        if (x == 1) {
            // Set all edges to RockWalls, will replace with doors in further functions
            r = new core::dungeon::basic::RockChamber(id);
            r->setNorth(new RockWall(North));
            r->setEast(new RockWall(East));
            r->setSouth(new RockWall(South));
            r->setWest(new RockWall(West));
            level->addRoom(r);

        } else if (x == 2) {
            //std::make_shared<QuartzChamber>(new core::dungeon::basic::QuartzChamber(id));
            r = new core::dungeon::basic::QuartzChamber(id);
            r->setNorth(new RockWall(North));
            r->setEast(new RockWall(East));
            r->setSouth(new RockWall(South));
            r->setWest(new RockWall(West));
            level->addRoom(r);
        }

        return r;
    }
}

DungeonLevel* BasicDungeonLevelBuilder::getDungeonLevel() {
    // needs transfer of ownership
    return level;
}

void BasicDungeonLevelBuilder::buildExit(Room* room, Direction direction) {
    if (direction == North)
        room->setNorth(new core::dungeon::common::OneWayDoor(North, false, true));
     else if (direction == East)
        room->setEast(new core::dungeon::common::OneWayDoor(East, false, true));
     else if (direction == South)
        room->setSouth(new core::dungeon::common::OneWayDoor(South, false, true));
     else if (direction == West)
        room->setWest(new core::dungeon::common::OneWayDoor(West, false, true));
}

void BasicDungeonLevelBuilder::buildEntrance(Room* room, Direction direction) {
    if (direction == North)
        room->setNorth(new core::dungeon::common::OneWayDoor(North, true, false));
     else if (direction == East)
        room->setEast(new core::dungeon::common::OneWayDoor(East, true, false));
     else if (direction == South)
        room->setSouth(new core::dungeon::common::OneWayDoor(South, true, false));
     else if (direction == West)
        room->setWest(new core::dungeon::common::OneWayDoor(West, true, false));
}

void BasicDungeonLevelBuilder::buildDoorway(Room* origin, Room* destination, Direction direction, MoveConstraints constraints) {
    /** This is literally the worst code i've ever written and spits in the face of D.R.Y., but
     * I already committed to using getN/E/S/W in other functions...
     * might change the setN/E/S/W functions to a more modular function later if I get time*/

    /** OpenDoorway @ Origin & Destination */
    if (constraints == 0) {
        if (direction == Direction::North) {
            origin->setNorth(new core::dungeon::common::OpenDoorway(direction));
            destination->setSouth(new core::dungeon::common::OpenDoorway(Direction::South));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getNorth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getSouth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {
            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::East) {
            origin->setEast(new core::dungeon::common::OpenDoorway(direction));
            destination->setWest(new core::dungeon::common::OpenDoorway(Direction::West));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getEast());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getWest());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::South) {
            origin->setSouth(new core::dungeon::common::OpenDoorway(direction));
            destination->setNorth(new core::dungeon::common::OpenDoorway(Direction::North));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getSouth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getNorth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::West) {
            origin->setWest(new core::dungeon::common::OpenDoorway(direction));
            destination->setEast(new core::dungeon::common::OpenDoorway(Direction::East));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getWest());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getEast());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        }
    }
    /** OneWayDoor @ Origin, OpenDoorway @ Destination */
    else if (constraints == 1) {
        if (direction == Direction::North) {
            origin->setNorth(new core::dungeon::common::OneWayDoor(direction, false, false));
            destination->setSouth(new core::dungeon::common::OneWayDoor(North, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getNorth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getSouth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::East) {
            origin->setEast(new core::dungeon::common::OneWayDoor(direction, false, false));
            destination->setWest(new core::dungeon::common::OneWayDoor(East, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getEast());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getWest());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {
            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::South) {
            origin->setSouth(new core::dungeon::common::OneWayDoor(direction, false, false));
            destination->setNorth(new core::dungeon::common::OneWayDoor(South, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getSouth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getNorth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }

        } else if (direction == Direction::West) {
            origin->setWest(new core::dungeon::common::OneWayDoor(direction, false, false));
            destination->setEast(new core::dungeon::common::OneWayDoor(West, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getWest());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getEast());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        }

        /** OpenDoorway @ Origin, OneWayDoor @ Destination */
    } else if (constraints == 2) {
        if (direction == Direction::North) {
            origin->setNorth(new core::dungeon::common::OpenDoorway(direction));
            destination->setSouth(new core::dungeon::common::OneWayDoor(Direction::South, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getNorth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getSouth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::East) {
            origin->setEast(new core::dungeon::common::OpenDoorway(direction));
            destination->setWest(new core::dungeon::common::OneWayDoor(Direction::West, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getEast());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getWest());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::South) {
            origin->setSouth(new core::dungeon::common::OpenDoorway(direction));
            destination->setNorth(new core::dungeon::common::OneWayDoor(Direction::North, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getSouth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getNorth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }

        } else if (direction == Direction::West) {
            origin->setWest(new core::dungeon::common::OpenDoorway(direction));
            destination->setEast(new core::dungeon::common::OneWayDoor(Direction::East, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getWest());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getEast());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        }

        /** BlockDoorway @ Origin & Destination */
    } else if (constraints == 3) {
        if (direction == Direction::North) {
            origin->setNorth(new core::dungeon::common::BlockedDoorWay(direction));
            destination->setSouth(new core::dungeon::common::BlockedDoorWay(Direction::South));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getNorth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getSouth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::East) {
            origin->setEast(new core::dungeon::common::BlockedDoorWay(direction));
            destination->setWest(new core::dungeon::common::BlockedDoorWay(Direction::West));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getEast());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getWest());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::South) {
            origin->setSouth(new core::dungeon::common::BlockedDoorWay(direction));
            destination->setNorth(new core::dungeon::common::BlockedDoorWay(Direction::North));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getSouth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getNorth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }

        } else if (direction == Direction::West) {
            origin->setWest(new core::dungeon::common::BlockedDoorWay(direction));
            destination->setEast(new core::dungeon::common::BlockedDoorWay(Direction::East));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getWest());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getEast());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        }

        /** LockDoor @ Origin, OpenDoorway @ Destination */
    } else if (constraints == 4) {
        if (direction == Direction::North) {
            origin->setNorth(new core::dungeon::common::LockedDoor(direction));
            destination->setSouth(new core::dungeon::common::OpenDoorway(Direction::South));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getNorth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getSouth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::East) {
            origin->setEast(new core::dungeon::common::LockedDoor(direction));
            destination->setWest(new core::dungeon::common::OpenDoorway(Direction::West));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getEast());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getWest());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::South) {
            origin->setSouth(new core::dungeon::common::LockedDoor(direction));
            destination->setNorth(new core::dungeon::common::OpenDoorway(Direction::North));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getSouth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getNorth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::West) {
            origin->setWest(new core::dungeon::common::LockedDoor(direction));
            destination->setEast(new core::dungeon::common::OpenDoorway(Direction::East));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getWest());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getEast());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        }

        // do nothing, is entrance
    }  else if (constraints == 5) {

        /** LockedDoor @ Origin, OneWayDoor @ Destination */
    } else if (constraints == 6) {
        if (direction == Direction::North) {
            origin->setNorth(new core::dungeon::common::LockedDoor(direction));
            destination->setSouth(new core::dungeon::common::OneWayDoor(Direction::South, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getNorth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getSouth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::East) {
            origin->setEast(new core::dungeon::common::LockedDoor(direction));
            destination->setWest(new core::dungeon::common::OneWayDoor(Direction::West, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getEast());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getWest());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::South) {
            origin->setSouth(new core::dungeon::common::LockedDoor(direction));
            destination->setNorth(new core::dungeon::common::OneWayDoor(Direction::North, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getSouth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getWest());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::West) {
            origin->setWest(new core::dungeon::common::LockedDoor(direction));
            destination->setEast(new core::dungeon::common::OneWayDoor(Direction::East, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getWest());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getEast());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        }

        /** OpenDoorway @ Origin, LockedDoor @ Destination */
    } else if (constraints == 8) {
        if (direction == Direction::North) {
            origin->setNorth(new core::dungeon::common::OpenDoorway(direction));
            destination->setSouth(new core::dungeon::common::LockedDoor(Direction::South));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getNorth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getSouth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::East) {
            origin->setEast(new core::dungeon::common::OpenDoorway(direction));
            destination->setWest(new core::dungeon::common::LockedDoor(Direction::West));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getEast());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getWest());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::South) {
            origin->setSouth(new core::dungeon::common::OpenDoorway(direction));
            destination->setNorth(new core::dungeon::common::LockedDoor(Direction::North));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getSouth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getNorth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::West) {
            origin->setWest(new core::dungeon::common::OpenDoorway(direction));
            destination->setEast(new core::dungeon::common::LockedDoor(Direction::East));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getWest());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getEast());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        }

        /** LockedDoor @ Origin, OneWayDoor @ Destination */
    } else if (constraints == 9) {
        if (direction == Direction::North) {
            origin->setNorth(new core::dungeon::common::LockedDoor(direction));
            destination->setSouth(new core::dungeon::common::OneWayDoor(Direction::South, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getNorth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getSouth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::East) {
            origin->setEast(new core::dungeon::common::LockedDoor(direction));
            destination->setWest(new core::dungeon::common::OneWayDoor(Direction::West, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getEast());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getWest());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::South) {
            origin->setSouth(new core::dungeon::common::LockedDoor(direction));
            destination->setNorth(new core::dungeon::common::OneWayDoor(Direction::North, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getSouth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getNorth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::West) {
            origin->setWest(new core::dungeon::common::LockedDoor(direction));
            destination->setEast(new core::dungeon::common::OneWayDoor(Direction::East, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getWest());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getEast());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        }

        /** do nothing, is exit */
    } else if (constraints == 10) {

        /** LockDoor @ Origin & Destination */
    } else if (constraints == 12) {
        if (direction == Direction::North) {
            origin->setNorth(new core::dungeon::common::LockedDoor(direction));
            destination->setSouth(new core::dungeon::common::LockedDoor(Direction::South));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getNorth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getSouth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::East) {
            origin->setEast(new core::dungeon::common::LockedDoor(direction));
            destination->setWest(new core::dungeon::common::LockedDoor(Direction::West));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getEast());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getWest());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::South) {
            origin->setSouth(new core::dungeon::common::LockedDoor(direction));
            destination->setNorth(new core::dungeon::common::LockedDoor(Direction::North));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getSouth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getNorth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        } else if (direction == Direction::West) {
            origin->setWest(new core::dungeon::common::LockedDoor(direction));
            destination->setEast(new core::dungeon::common::LockedDoor(Direction::East));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getWest());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getEast());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
                d2->connect(d1);
            }
        }
    }
}

int BasicDungeonLevelBuilder::getRandomNumber(int min, int max) {
    // I've tried like 5 different methods of getting random integers and they're all
    // seeded and end up giving the same results every single time the program runs. This was the best I could come up with,
    // It's mostly random but each program start one or two digits generally stay the same.
    static constexpr double fraction { 1.0 / (RAND_MAX + 1.0) };  // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

}
