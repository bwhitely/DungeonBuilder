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

namespace core{

}
Test::Test()
{

}

void Test::test()
{
    Direction w = Direction::North;
    Direction w2 = Direction::East;
    Direction w3 = Direction::South;
    Direction d4 = Direction::West;

    core::dungeon::basic::RockWall* rockwall = new core::dungeon::basic::RockWall(w);
    std::cout << rockwall->description() << "\n";
    delete rockwall;

    core::dungeon::magical::MagicWall* mw = new core::dungeon::magical::MagicWall(w2);
    std::cout << mw->description() << "\n";
    delete mw;

    core::dungeon::common::OpenDoorway* opendw = new core::dungeon::common::OpenDoorway(w, false, false);
    std::cout << opendw->description();

    core::dungeon::common::OpenDoorway* opendw2 = new core::dungeon::common::OpenDoorway(w3, false, false);

    opendw->connect(opendw2);
    delete opendw2;

    core::dungeon::basic::RockChamber r = core::dungeon::basic::RockChamber(1);
    core::dungeon::common::OneWayDoor* owd = new core::dungeon::common::OneWayDoor(w, false, false);
    core::dungeon::common::OneWayDoor* owd2 = new core::dungeon::common::OneWayDoor(w3, false, false);
    owd->connect(owd2);
    delete owd;


}
