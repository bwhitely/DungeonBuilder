#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H
#include <string>
#include <Core/Dungeon/room.h>

namespace core::dungeon {
class DungeonLevelBuilder
{
public:
    DungeonLevelBuilder();
    void buildDungeonLevel(std::string name, int width, int height);
    Room buildRoom(int id);
    Room buildDoorway(Room origin, Room destination, core::dungeon::Room::Direction direction, MoveConstraints constraints);
};
}


#endif // DUNGEONLEVELBUILDER_H
