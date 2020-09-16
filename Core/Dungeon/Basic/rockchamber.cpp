#include "rockchamber.h"

namespace core::dungeon::basic{

RockChamber::RockChamber(const int id) : Room{id}
{

}

RockChamber::~RockChamber()
{
    delete this;
}

std::string RockChamber::description() const
{
    return "A chamber that intimidates those who enter. (Rock Chamber) \n"
            "To the NORTH is a \n"
            "To the SOUTH \n"
            "To the EAST \n"
            "To the WEST \n"
            "There is a x to fight. \n"
            "There is a x to pick up. \n";
}


}
