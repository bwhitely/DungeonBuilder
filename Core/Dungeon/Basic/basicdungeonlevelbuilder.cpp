#include "basicdungeonlevelbuilder.h"

namespace core::dungeon::basic {
BasicDungeonLevelBuilder::BasicDungeonLevelBuilder()
{

}

void BasicDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height)
{

}

Room BasicDungeonLevelBuilder::buildRoom(int id)
{

}

Room BasicDungeonLevelBuilder::buildDoorway(Room origin, Room destination, Room::Direction direction, DungeonLevelBuilder::MoveConstraints constraints)
{

}

void BasicDungeonLevelBuilder::buildEntrance(Room room, Room::Direction direction, DungeonLevelBuilder::MoveConstraints constraints)
{

}

void BasicDungeonLevelBuilder::buildExit(Room room, Room::Direction direction)
{

}

void BasicDungeonLevelBuilder::buildItem(Room)
{

}

void BasicDungeonLevelBuilder::buildCreature(Room)
{

}

DungeonLevel BasicDungeonLevelBuilder::getDungeonLevel()
{

}
}


