#include "basicdungeonlevel.h"

namespace core::dungeon::basic{

BasicDungeonLevel::BasicDungeonLevel(std::string name, int width, int height) : DungeonLevel(name, width, height)
{
    _name = name;
    _width = width;
    _height = height;
}

BasicDungeonLevel::~BasicDungeonLevel()
{

}

std::string BasicDungeonLevel::description()
{
    return "Description of BasicDungeonLevel";
}

}


