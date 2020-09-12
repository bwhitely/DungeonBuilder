#include "test.h"
#include <Core/Dungeon/doorway.h>
#include <Core/Dungeon/room.h>
#include <Core/Dungeon/roomedge.h>
#include <Core/Dungeon/wall.h>
#include <Core/Dungeon/Basic/rockwall.h>
#include <Core/Dungeon/Common/blockeddoorway.h>
#include <Core/Dungeon/Common/opendoorway.h>
#include <Core/Dungeon/Magical/magicwall.h>
#include <iostream>
#include <string>
#include <Core/Dungeon/Basic/rockchamber.h>
#include <Core/Dungeon/Common/onewaydoor.h>
#include <Core/Creatures/abstractcreature.h>
#include <Core/Creatures/monster.h>
#include <Core/Items/consumeable.h>
#include <Core/Items/item.h>
#include <Core/Items/weapon.h>
#include <Core/Dungeon/dungeonlevelbuilder.h>
#include <Core/Dungeon/Basic/basicdungeonlevelbuilder.h>
#include <Core/Dungeon/Basic/basicdungeonlevel.h>
#include <Core/game.h>
#include <Core/Dungeon/Basic/basicdungeonlevel.h>
#include <memory>

namespace core{

}
Test::Test()
{

}

void Test::test()
{
    Direction n = Direction::North;
    Direction e = Direction::East;
    Direction s = Direction::South;
    Direction w = Direction::West;

    // new rock chamber with id = 1
    core::dungeon::basic::RockChamber* r = new core::dungeon::basic::RockChamber(1);
    // set rock chamber's north RoomEdge as an OpenDoorway
    r->setNorth(new core::dungeon::common::OpenDoorway(n, false, false));
    // rock chamber's east to rock onewaydoor
    r->setEast(new core::dungeon::common::OneWayDoor(e, false, false));
    // south to opendoorway
    r->setSouth(new core::dungeon::common::OpenDoorway(s, false, false));
    // west to rockwall
    r->setWest(new core::dungeon::basic::RockWall(w));

    std::cout << r->description() << std::endl;
    std::cout << *r->getNorth() << std::endl;
    std::cout << *r->getEast() << std::endl;
    std::cout << *r->getSouth() << std::endl;
    std::cout << *r->getWest() << std::endl;

    Monster goblin = Monster("goblin");
    std::cout << goblin.name() << std::endl;

    core::items::Weapon weap = core::items::Weapon("Iron Axe");
    std::cout << weap.name() << std::endl;

//    core::Game* game = game->instance(); // director

//    // new concrete dungeon builder
//    std::unique_ptr<core::dungeon::basic::BasicDungeonLevelBuilder> bd{new core::dungeon::basic::BasicDungeonLevelBuilder()};

//    // game setDungeonType(concreteBuilder)
//    game->setDungeonType(std::move(bd));
//    // game create...Level(...)
//    game->createRandomLevel("Test Name", 2, 2);
//    // concreteBuilder buildDungeonLevel(name, width, height)
//    bd->BuildDungeonLevel("Test Name", 2, 2);

//    // concreteBuilder buildRoom()

//    core::dungeon::Room* r1 = bd->buildRoom(1);
//    bd->getDungeonLevel()->addRoom(r1);

    //core::dungeon::Doorway *dw = bd->buildDoorway(bd->getDungeonLevel()->retrieveRoom(1).)

    //game->displayLevel(std::cout);


}
