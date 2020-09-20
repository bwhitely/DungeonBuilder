#include "magicaldungeonlevelbuilder.h"
#include <random>
#include <time.h>
#include <Core/Dungeon/Magical/alchemistslaboratory.h>
#include <Core/Dungeon/Magical/enchantedlibrary.h>
#include <Core/Dungeon/Magical/magicwall.h>
#include <Core/Dungeon/Common/blockeddoorway.h>
#include <Core/Dungeon/Common/lockeddoor.h>
#include <Core/Dungeon/Common/onewaydoor.h>
#include <Core/Dungeon/Common/opendoorway.h>

namespace core::dungeon::magical{

MagicalDungeonLevelBuilder::MagicalDungeonLevelBuilder()
{
    srand(time(NULL));
    // add items to vectors
    items.push_back(std::unique_ptr<items::Item>(new core::items::Consumeable("Health Potion")));
    items.push_back(std::unique_ptr<items::Item>(new core::items::Consumeable("Molotov Cocktail")));
    items.push_back(std::unique_ptr<items::Item>(new core::items::Consumeable("Smoke Bomb")));
    items.push_back(std::unique_ptr<items::Item>(new core::items::Consumeable("Resistance Potion")));
    items.push_back(std::unique_ptr<items::Item>(new core::items::Weapon("Boomerang")));
    items.push_back(std::unique_ptr<items::Item>(new core::items::Weapon("Wizard's Staff")));
    items.push_back(std::unique_ptr<items::Item>(new core::items::Weapon("Magic Wand")));

    // add creatures to vectors
    creatures.push_back(std::unique_ptr<AbstractCreature>(new Monster("Goblin")));
    creatures.push_back(std::unique_ptr<AbstractCreature>(new Monster("Dragon")));
    creatures.push_back(std::unique_ptr<AbstractCreature>(new Monster("Evil Wizard")));
}

MagicalDungeonLevelBuilder::~MagicalDungeonLevelBuilder()
{
    level = nullptr;
}

void MagicalDungeonLevelBuilder::BuildDungeonLevel(std::string name, int width, int height)
{
    level = new MagicalDungeonLevel(name, width, height);
}

void MagicalDungeonLevelBuilder::buildItem(Room *room)
{
    int r = getRandomNumber(1, 100);
    int r2 = getRandomNumber(1, 3);

    // Roughly a 65% chance it's a Consumeable
    if (r <= 65) {
        if (r2 == 1)
            room->setItem(items.at(0)->clone());
        else if (r2 == 2)
            room->setItem(items.at(1)->clone());
        else if (r == 3)
            room->setItem(items.at(2)->clone());

        // Roughly a 35% chance it's a Weapon
    } else if (r > 65) {
        if (r2 == 1)
            room->setItem(items.at(3)->clone());

        if (r2 == 2)
            room->setItem(items.at(4)->clone());

        if (r2 == 3)
            room->setItem(items.at(5)->clone());
    }
}

void MagicalDungeonLevelBuilder::buildCreature(Room *room)
{
    int r = getRandomNumber(1, 3);

    // clone existing creature into room
    if (r == 1)
        room->setCreature(creatures.at(0)->clone());
    else if (r == 2)
        room->setCreature(creatures.at(1)->clone());
    else if (r == 3)
        room->setCreature(creatures.at(2)->clone());

    // If this is the last room, set the creature to a boss.
    if (room->containsExit()) {
        room->creature().setBoss();
    }
}

Room *MagicalDungeonLevelBuilder::buildRoom(int id)
{
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
            r = new core::dungeon::magical::EnchantedLibrary(id);
            r->setNorth(new MagicWall(North));
            r->setEast(new MagicWall(East));
            r->setSouth(new MagicWall(South));
            r->setWest(new MagicWall(West));
            level->addRoom(r);
            //level->addRoom(std::make_shared<Room>(r));

        } else if (x == 2) {
            //std::make_shared<QuartzChamber>(new core::dungeon::basic::QuartzChamber(id));
            r = new core::dungeon::magical::AlchemistsLaboratory(id);
            r->setNorth(new MagicWall(North));
            r->setEast(new MagicWall(East));
            r->setSouth(new MagicWall(South));
            r->setWest(new MagicWall(West));
            level->addRoom(r);
            //level->addRoom(std::make_shared<Room>(r));
        }

        return r;
    }
}

DungeonLevel *MagicalDungeonLevelBuilder::getDungeonLevel()
{
    return level;
}

void MagicalDungeonLevelBuilder::buildExit(Room *room, Direction direction)
{
    // Builds exit in specified direction in passed Room
    if (direction == North)
        room->setNorth(new core::dungeon::common::OneWayDoor(North, false, true));
    else if (direction == East)
        room->setEast(new core::dungeon::common::OneWayDoor(East, false, true));
    else if (direction == South)
        room->setSouth(new core::dungeon::common::OneWayDoor(South, false, true));
    else if (direction == West)
        room->setWest(new core::dungeon::common::OneWayDoor(West, false, true));
}

void MagicalDungeonLevelBuilder::buildEntrance(Room *room, Direction direction)
{
    // Builds entrance in specified direction in passed Room
    if (direction == North)
        room->setNorth(new core::dungeon::common::OneWayDoor(North, true, false));
    else if (direction == East)
        room->setEast(new core::dungeon::common::OneWayDoor(East, true, false));
    else if (direction == South)
        room->setSouth(new core::dungeon::common::OneWayDoor(South, true, false));
    else if (direction == West)
        room->setWest(new core::dungeon::common::OneWayDoor(West, true, false));
}

void MagicalDungeonLevelBuilder::buildDoorway(Room *origin, Room *destination, Direction direction, MoveConstraints constraints)
{
    // Get opposite direction
    Direction opp = getOpposite(direction);
    /** OpenDoorway @ Origin & Destination */
    if (constraints == 0) {
        origin->setEdge(direction, "open");
        destination->setEdge(opp, "open");
        // cast to Doorway* and conect doorways
        Doorway* d1 = dynamic_cast<Doorway*>(origin->getEdge(direction));
        Doorway* d2 = dynamic_cast<Doorway*>(destination->getEdge(opp));

        // check for nullptr, ie. edge isnt a doorway
        if (d1 == nullptr || d2 == nullptr) {
        } else {
            d1->connect(d2);
            d2->connect(d1);
        }
    }
    /** OneWayDoor @ Origin, OpenDoorway @ Destination */
    else if (constraints == 1) {
        origin->setEdge(direction, "oneway");
        destination->setEdge(opp, "open");
        // cast to Doorway* and conect doorways
        Doorway* d1 = dynamic_cast<Doorway*>(origin->getEdge(direction));
        Doorway* d2 = dynamic_cast<Doorway*>(destination->getEdge(opp));

        // check for nullptr, ie. edge isnt a doorway
        if (d1 == nullptr || d2 == nullptr) {
        } else {
            d1->connect(d2);
            d2->connect(d1);
        }

        /** OpenDoorway @ Origin, OneWayDoor @ Destination */
    } else if (constraints == 2) {
        origin->setEdge(direction, "open");
        destination->setEdge(opp, "oneway");
        // cast to Doorway* and conect doorways
        Doorway* d1 = dynamic_cast<Doorway*>(origin->getEdge(direction));
        Doorway* d2 = dynamic_cast<Doorway*>(destination->getEdge(opp));

        // check for nullptr, ie. edge isnt a doorway
        if (d1 == nullptr || d2 == nullptr) {
        } else {
            d1->connect(d2);
            d2->connect(d1);
        }

        /** BlockDoorway @ Origin & Destination */
    } else if (constraints == 3) {
        origin->setEdge(direction, "blocked");
        destination->setEdge(opp, "blocked");
        // cast to Doorway* and conect doorways
        Doorway* d1 = dynamic_cast<Doorway*>(origin->getEdge(direction));
        Doorway* d2 = dynamic_cast<Doorway*>(destination->getEdge(opp));

        // check for nullptr, ie. edge isnt a doorway
        if (d1 == nullptr || d2 == nullptr) {
        } else {
            d1->connect(d2);
            d2->connect(d1);
        }

        /** LockDoor @ Origin, OpenDoorway @ Destination */
    } else if (constraints == 4) {
        origin->setEdge(direction, "locked");
        destination->setEdge(opp, "open");
        // cast to Doorway* and conect doorways
        Doorway* d1 = dynamic_cast<Doorway*>(origin->getEdge(direction));
        Doorway* d2 = dynamic_cast<Doorway*>(destination->getEdge(opp));

        // check for nullptr, ie. edge isnt a doorway
        if (d1 == nullptr || d2 == nullptr) {
        } else {
            d1->connect(d2);
            d2->connect(d1);
        }
    }

    /** LockedDoor @ Origin, OneWayDoor @ Destination */
    else if (constraints == 6) {
        origin->setEdge(direction, "locked");
        destination->setEdge(opp, "oneway");
        // cast to Doorway* and conect doorways
        Doorway* d1 = dynamic_cast<Doorway*>(origin->getEdge(direction));
        Doorway* d2 = dynamic_cast<Doorway*>(destination->getEdge(opp));

        // check for nullptr, ie. edge isnt a doorway
        if (d1 == nullptr || d2 == nullptr) {
        } else {
            d1->connect(d2);
            d2->connect(d1);
        }

        /** OpenDoorway @ Origin, LockedDoor @ Destination */
    } else if (constraints == 8) {
        origin->setEdge(direction, "open");
        destination->setEdge(opp, "locked");
        // cast to Doorway* and conect doorways
        Doorway* d1 = dynamic_cast<Doorway*>(origin->getEdge(direction));
        Doorway* d2 = dynamic_cast<Doorway*>(destination->getEdge(opp));

        // check for nullptr, ie. edge isnt a doorway
        if (d1 == nullptr || d2 == nullptr) {
        } else {
            d1->connect(d2);
            d2->connect(d1);
        }

        /** LockedDoor @ Origin, OneWayDoor @ Destination */
    } else if (constraints == 9) {
        origin->setEdge(direction, "locked");
        destination->setEdge(opp, "oneway");
        // cast to Doorway* and conect doorways
        Doorway* d1 = dynamic_cast<Doorway*>(origin->getEdge(direction));
        Doorway* d2 = dynamic_cast<Doorway*>(destination->getEdge(opp));

        // check for nullptr, ie. edge isnt a doorway
        if (d1 == nullptr || d2 == nullptr) {
        } else {
            d1->connect(d2);
            d2->connect(d1);
        }

    }

    /** LockDoor @ Origin & Destination */
    else if (constraints == 12) {
        origin->setEdge(direction, "locked");
        destination->setEdge(opp, "locked");
        // cast to Doorway* and conect doorways
        Doorway* d1 = dynamic_cast<Doorway*>(origin->getEdge(direction));
        Doorway* d2 = dynamic_cast<Doorway*>(destination->getEdge(opp));

        // check for nullptr, ie. edge isnt a doorway
        if (d1 == nullptr || d2 == nullptr) {
        } else {
            d1->connect(d2);
            d2->connect(d1);
        }
    }
}

int MagicalDungeonLevelBuilder::getRandomNumber(int min, int max)
{
    static constexpr double fraction { 1.0 / (RAND_MAX + 1.0) };  // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

Direction MagicalDungeonLevelBuilder::getOpposite(Direction direction)
{
    // Returns opposite direction to the passed direction
    if (direction == North)
        return South;
    else if (direction == South)
        return North;
    else if (direction == East)
        return West;
    else if (direction == West)
        return East;
}

}

