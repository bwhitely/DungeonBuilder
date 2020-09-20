#include "rockchamber.h"
#include <iostream>

namespace core::dungeon::basic{

RockChamber::RockChamber(const int id) : Room{id}
{

}

RockChamber::~RockChamber()
{

}

std::string RockChamber::description () const
{
    return "A dark, gloomy chamber. (Rock Chamber) \n";
}


}
