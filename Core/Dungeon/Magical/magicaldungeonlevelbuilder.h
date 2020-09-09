#ifndef MAGICALDUNGEONLEVELBUILDER_H
#define MAGICALDUNGEONLEVELBUILDER_H
#include <Core/Dungeon/dungeonlevelbuilder.h>

namespace core::dungeon::magical {
class MagicalDungeonLevelBuilder : public DungeonLevelBuilder
{
public:
    MagicalDungeonLevelBuilder();
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


#endif // MAGICALDUNGEONLEVELBUILDER_H
