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
    std::string s = name() + "\n";
            s += "Size: " + std::to_string(width()) + " x " + std::to_string(height()) + "\n";
            s += "Type: Wizardly Palace (Magical Dungeon)\n";
    return s;
}

}

