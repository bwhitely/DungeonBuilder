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

using namespace std;
using namespace core;
using namespace core::dungeon;
using namespace core::dungeon::basic;
using namespace core::dungeon::magical;
using namespace core::dungeon::common;
using namespace core::items;
using namespace core::creatures;

namespace core {

}
Test::Test() {

}

void Test::test() {

    core::Game* game = game->instance(); // director

    // new concrete dungeon builder
    std::unique_ptr<core::dungeon::basic::BasicDungeonLevelBuilder> bd{new core::dungeon::basic::BasicDungeonLevelBuilder()};

    // game setDungeonType(concreteBuilder)
    game->setDungeonType(std::move(bd));
    // game create...Level(...)
    //game->createRandomLevel("Test Name", 2, 2);
    game->createExampleLevel();

}
