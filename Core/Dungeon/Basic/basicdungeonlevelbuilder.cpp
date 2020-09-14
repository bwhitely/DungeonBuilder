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
}

BasicDungeonLevelBuilder::~BasicDungeonLevelBuilder() {
    level = nullptr;
}

void BasicDungeonLevelBuilder::BuildDungeonLevel(std::string name, int width, int height) {
    level = new BasicDungeonLevel(name, width, height);
}

void BasicDungeonLevelBuilder::buildItem(Room* room) {

    int r = getRandomNumber(1, 6);

    if (r == 1) {
        items::Item* i = new items::Item("Health Potion");
        room->setItem(i);
    } else if (r == 2) {
        items::Item* i = new items::Item("Molotov Cocktail");
        room->setItem(i);
    } else if (r == 3) {
        items::Item* i = new items::Item("Smoke Bomb");
        room->setItem(i);
    } else if (r == 4) {
        items::Item* i = new items::Item("Boomerang");
        room->setItem(i);
    } else if (r == 5) {
        items::Item* i = new items::Item("Short Sword");
        room->setItem(i);
    } else if (r == 6) {
        items::Item* i = new items::Item("Battle Axe");
        room->setItem(i);
    }
}

void BasicDungeonLevelBuilder::buildCreature(Room* room) {
//    Monster *m2 = new Monster("Monster");
//    AbstractCreature *m1 = m2->clone();
    int r = getRandomNumber(1, 3);

    if (r == 1) {
        Monster* m = new Monster("Goblin");
        room->setCreature(m);
    } else if (r == 2) {
        Monster* m = new Monster("Werewolf");
        room->setCreature(m);
    } else if (r == 3) {
        Monster* m = new Monster("Evil Wizard");
        room->setCreature(m);
    }

}

Room* BasicDungeonLevelBuilder::buildRoom(int id) {
    int x = getRandomNumber(1, 2);
    Room* r = nullptr;

    // level is null
    if (!level) {
        return nullptr;
        // level not null
    } else {
        if (x == 1) {
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
    if (direction == North) {
        room->setNorth(new core::dungeon::common::OneWayDoor(North, false, true));
    } else if (direction == East) {
        room->setEast(new core::dungeon::common::OneWayDoor(East, false, true));
    } else if (direction == South) {
        room->setSouth(new core::dungeon::common::OneWayDoor(South, false, true));
    } else if (direction == West) {
        room->setWest(new core::dungeon::common::OneWayDoor(West, false, true));
    }
}

void BasicDungeonLevelBuilder::buildEntrance(Room* room, Direction direction) {
    if (direction == North) {
        room->setNorth(new core::dungeon::common::OneWayDoor(North, true, false));
    } else if (direction == East) {
        room->setEast(new core::dungeon::common::OneWayDoor(East, true, false));
    } else if (direction == South) {
        room->setSouth(new core::dungeon::common::OneWayDoor(South, true, false));
    } else if (direction == West) {
        room->setWest(new core::dungeon::common::OneWayDoor(West, true, false));
    }
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
            }
        } else if (direction == Direction::South) {
            origin->setSouth(new core::dungeon::common::OpenDoorway(direction));
            origin->setNorth(new core::dungeon::common::OpenDoorway(Direction::North));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getSouth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getNorth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
            }
        } else if (direction == Direction::West) {
            origin->setWest(new core::dungeon::common::OpenDoorway(direction));
            origin->setEast(new core::dungeon::common::OpenDoorway(Direction::East));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getWest());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getEast());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
            }
        }
    }
    /** OneWayDoor @ Origin, OpenDoorway @ Destination */
    else if (constraints == 1) {
        if (direction == Direction::North) {
            origin->setNorth(new core::dungeon::common::OneWayDoor(direction, false, false));
            destination->setSouth(new core::dungeon::common::OpenDoorway(Direction::South));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getNorth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getSouth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
            }
        } else if (direction == Direction::East) {
            origin->setEast(new core::dungeon::common::OneWayDoor(direction, false, false));
            destination->setWest(new core::dungeon::common::OpenDoorway(Direction::West));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getEast());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getWest());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {
            } else {
                d1->connect(d2);
            }
        } else if (direction == Direction::South) {
            origin->setSouth(new core::dungeon::common::OneWayDoor(direction, false, false));
            origin->setNorth(new core::dungeon::common::OpenDoorway(Direction::North));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getSouth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getNorth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
            }

        } else if (direction == Direction::West) {
            origin->setWest(new core::dungeon::common::OneWayDoor(direction, false, false));
            origin->setEast(new core::dungeon::common::OpenDoorway(Direction::East));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getWest());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getEast());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
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
            }
        } else if (direction == Direction::South) {
            origin->setSouth(new core::dungeon::common::OpenDoorway(direction));
            origin->setNorth(new core::dungeon::common::OneWayDoor(Direction::North, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getSouth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getNorth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
            }

        } else if (direction == Direction::West) {
            origin->setWest(new core::dungeon::common::OpenDoorway(direction));
            origin->setEast(new core::dungeon::common::OneWayDoor(Direction::East, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getWest());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getEast());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
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
            }
        } else if (direction == Direction::South) {
            origin->setSouth(new core::dungeon::common::BlockedDoorWay(direction));
            origin->setNorth(new core::dungeon::common::BlockedDoorWay(Direction::North));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getSouth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getNorth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
            }

        } else if (direction == Direction::West) {
            origin->setWest(new core::dungeon::common::BlockedDoorWay(direction));
            origin->setEast(new core::dungeon::common::BlockedDoorWay(Direction::East));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getWest());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getEast());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
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
            }
        } else if (direction == Direction::South) {
            origin->setSouth(new core::dungeon::common::LockedDoor(direction));
            origin->setNorth(new core::dungeon::common::OpenDoorway(Direction::North));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getSouth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getNorth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
            }
        } else if (direction == Direction::West) {
            origin->setWest(new core::dungeon::common::LockedDoor(direction));
            origin->setEast(new core::dungeon::common::OpenDoorway(Direction::East));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getWest());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getEast());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
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
            }
        } else if (direction == Direction::South) {
            origin->setSouth(new core::dungeon::common::LockedDoor(direction));
            origin->setNorth(new core::dungeon::common::OneWayDoor(Direction::North, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getSouth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getWest());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
            }
        } else if (direction == Direction::West) {
            origin->setWest(new core::dungeon::common::LockedDoor(direction));
            origin->setEast(new core::dungeon::common::OneWayDoor(Direction::East, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getWest());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getEast());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
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
            }
        } else if (direction == Direction::South) {
            origin->setSouth(new core::dungeon::common::OpenDoorway(direction));
            origin->setNorth(new core::dungeon::common::LockedDoor(Direction::North));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getSouth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getNorth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
            }
        } else if (direction == Direction::West) {
            origin->setWest(new core::dungeon::common::OpenDoorway(direction));
            origin->setEast(new core::dungeon::common::LockedDoor(Direction::East));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getWest());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getEast());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
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
            }
        } else if (direction == Direction::South) {
            origin->setSouth(new core::dungeon::common::LockedDoor(direction));
            origin->setNorth(new core::dungeon::common::OneWayDoor(Direction::North, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getSouth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getNorth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
            }
        } else if (direction == Direction::West) {
            origin->setWest(new core::dungeon::common::LockedDoor(direction));
            origin->setEast(new core::dungeon::common::OneWayDoor(Direction::East, false, false));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getWest());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getEast());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
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
            }
        } else if (direction == Direction::South) {
            origin->setSouth(new core::dungeon::common::LockedDoor(direction));
            origin->setNorth(new core::dungeon::common::LockedDoor(Direction::North));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getSouth());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getNorth());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
            }
        } else if (direction == Direction::West) {
            origin->setWest(new core::dungeon::common::LockedDoor(direction));
            origin->setEast(new core::dungeon::common::LockedDoor(Direction::East));
            // cast to Doorway* and conect doorways
            Doorway* d1 = dynamic_cast<Doorway*>(origin->getWest());
            Doorway* d2 = dynamic_cast<Doorway*>(destination->getEast());

            // check for nullptr, ie. edge isnt a doorway
            if (d1 == nullptr || d2 == nullptr) {

            } else {
                d1->connect(d2);
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
