#include "magicaldungeonlevelbuilder.h"

namespace core::dungeon::magical{
MagicalDungeonLevelBuilder::MagicalDungeonLevelBuilder()
{

}

void MagicalDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height)
{

}

Room MagicalDungeonLevelBuilder::buildRoom(int id)
{

}

Room MagicalDungeonLevelBuilder::buildDoorway(Room origin, Room destination, Room::Direction direction, DungeonLevelBuilder::MoveConstraints constraints)
{

}

void MagicalDungeonLevelBuilder::buildEntrance(Room room, Room::Direction direction, DungeonLevelBuilder::MoveConstraints constraints)
{

}

void MagicalDungeonLevelBuilder::buildExit(Room room, Room::Direction direction)
{

}

void MagicalDungeonLevelBuilder::buildItem(Room)
{

}

void MagicalDungeonLevelBuilder::buildCreature(Room)
{

}

DungeonLevel MagicalDungeonLevelBuilder::getDungeonLevel()
{

}
}

