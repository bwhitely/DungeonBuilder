#include "magicaldungeonlevelbuilder.h"

namespace core::dungeon::magical{

MagicalDungeonLevelBuilder::MagicalDungeonLevelBuilder()
{

}

MagicalDungeonLevelBuilder::~MagicalDungeonLevelBuilder()
{
    level = nullptr;
}

void MagicalDungeonLevelBuilder::BuildDungeonLevel(std::string name, int width, int height)
{

}

void MagicalDungeonLevelBuilder::buildItem(Room *)
{

}

Room *MagicalDungeonLevelBuilder::buildRoom(int id)
{

}

void MagicalDungeonLevelBuilder::buildCreature(Room *)
{

}

DungeonLevel *MagicalDungeonLevelBuilder::getDungeonLevel()
{

}

void MagicalDungeonLevelBuilder::buildExit(Room *room, Direction direction)
{

}

void MagicalDungeonLevelBuilder::buildEntrance(Room *room, Direction direction)
{

}

void MagicalDungeonLevelBuilder::buildDoorway(Room *origin, Room *destination, Direction direction, MoveConstraints constraints)
{

}

int MagicalDungeonLevelBuilder::getRandomNumber(int min, int max)
{

}

}

