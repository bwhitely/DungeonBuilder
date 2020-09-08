#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H
#include <string>
#include <Core/Dungeon/room.h>
#include <Core/Dungeon/dungeonlevel.h>

namespace core::dungeon {
class DungeonLevelBuilder
{
public:
    DungeonLevelBuilder();
    enum MoveConstraints : unsigned {None = 0, OriginImpassable = 1, DestinationImpassable = 2, OriginLocked = 4, DestinationLocked = 8};
    void buildDungeonLevel(std::string name, int width, int height);
    Room buildRoom(int id);
    Room buildDoorway(Room origin, Room destination, core::dungeon::Room::Direction direction, MoveConstraints constraints);
    void buildEntrance(Room room, core::dungeon::Room::Direction direction, MoveConstraints constraints);
    void buildExit(Room room, core::dungeon::Room::Direction direction);
    void buildItem(Room);
    void buildCreature(Room);
    DungeonLevel getDungeonLevel();
};
}


#endif // DUNGEONLEVELBUILDER_H
