#include "basicdungeonlevel.h"
#include <iostream>
#include <Core/Dungeon/Common/blockeddoorway.h>
#include <Core/Dungeon/Common/lockeddoor.h>
#include <Core/Dungeon/Common/onewaydoor.h>
#include <Core/Dungeon/Common/opendoorway.h>

namespace core::dungeon::basic {

BasicDungeonLevel::BasicDungeonLevel(std::string name, int width, int height) : DungeonLevel(name, width, height) {
    _name = name;
    _width = width;
    _height = height;
}

BasicDungeonLevel::~BasicDungeonLevel() {

}

/**
 * @brief BasicDungeonLevel::description
 * @return std::string description of level (name, size, type)
 */
std::string BasicDungeonLevel::description() {
    std::string s = "Name: " + name() + "\n";
    s += "Size: " + std::to_string(width()) + " x " + std::to_string(height()) + "\n";
    s += "Type: Dark Cave (Basic Dungeon)\n";
    return s;
}

}


