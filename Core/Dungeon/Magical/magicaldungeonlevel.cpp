#include "magicaldungeonlevel.h"
#include <Core/Dungeon/doorway.h>
#include <Core/Dungeon/Common/blockeddoorway.h>

namespace core::dungeon::magical {

MagicalDungeonLevel::MagicalDungeonLevel(std::string name, int width, int height) : DungeonLevel(name, width, height) {
    _name = name;
    _width = width;
    _height = height;
}

MagicalDungeonLevel::~MagicalDungeonLevel() {
    // This was the only way I could get SOME Doorways to be destroyed.
    // If i added to this and dynamic cast all types of doors, it segfaults
    for (int i = 0; i < numberOfRooms(); i++){
        if (core::dungeon::Doorway* d = dynamic_cast<core::dungeon::common::BlockedDoorWay*>(retrieveRoom(i+1)->getEdge(West)))
            delete d;
        if (core::dungeon::Doorway* d = dynamic_cast<core::dungeon::common::BlockedDoorWay*>(retrieveRoom(i+1)->getEdge(East)))
            delete d;
        if (core::dungeon::Doorway* d = dynamic_cast<core::dungeon::common::BlockedDoorWay*>(retrieveRoom(i+1)->getEdge(North)))
            delete d;
        if (core::dungeon::Doorway* d = dynamic_cast<core::dungeon::common::BlockedDoorWay*>(retrieveRoom(i+1)->getEdge(South)))
            delete d;
    }

}

/**
 * @brief MagicalDungeonLevel::description - Description of MagicalDungeonLevel (name, size, type)
 * @return
 */
std::string MagicalDungeonLevel::description() {
    std::string s = "Name: " + name() + "\n";
    s += "Size: " + std::to_string(width()) + " x " + std::to_string(height()) + "\n";
    s += "Type: Wizardly Palace (Magical Dungeon)\n";
    return s;
}

}
