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
    std::cout << r->getNorth() << std::endl;
    std::cout << r->getEast() << std::endl;
    std::cout << r->getSouth() << std::endl;
    std::cout << r->getWest() << std::endl;

    Monster* m = new Monster("Goblin");
    std::cout << m->name() << std::endl;
    Monster goblin = Monster("goblin");
    goblin.name();

    core::items::Weapon weap = core::items::Weapon("Iron Axe");
    std::cout << weap.name() << std::endl;

    core::dungeon::basic::BasicDungeonLevelBuilder b = core::dungeon::basic::BasicDungeonLevelBuilder();

    core::Game *game = game->instance();
    game->setDungeonType(b);
    game->displayLevel();

    b.BuildDungeonLevel("Cool Dungeon", 2, 2);

    for (int i = 0; i < 5; i++){
        b.buildRoom(i);
    }

    for (int i = 0; i < 4; i++){
        b.buildDoorway(b.rooms.at(i), b.rooms.at(i+1), e, MoveConstraints::None);
    }

    b.buildEntrance(b.rooms.at(1), Direction::South);
    int size = b.rooms.size()-1;
    b.buildExit(b.rooms.at(size), Direction::North);

    b.buildItem(b.rooms.at(1));
    b.buildCreature(b.rooms.at(2));

    b.rooms.at(1)->creature();
    b.getDungeonLevel();

}
