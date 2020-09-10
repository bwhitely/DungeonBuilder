#include "rockchamber.h"

namespace core::dungeon::basic{

RockChamber::RockChamber(const int id) : Room{id}
{

}

RockChamber::~RockChamber()
{

}

std::string RockChamber::description() const
{
    return "Rock Chamber";
}


}
