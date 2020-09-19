#include "magicaldungeonlevel.h"

namespace core::dungeon::magical{

MagicalDungeonLevel::MagicalDungeonLevel(std::string name, int width, int height) : DungeonLevel(name, width, height)
{
    _name = name;
    _width = width;
    _height = height;
}

MagicalDungeonLevel::~MagicalDungeonLevel()
{

}

std::string MagicalDungeonLevel::description()
{
    return "magical dungeon";
}

}

