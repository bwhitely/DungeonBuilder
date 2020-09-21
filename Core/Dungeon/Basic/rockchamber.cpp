#include "rockchamber.h"
#include <iostream>

namespace core::dungeon::basic {

RockChamber::RockChamber(const int id) : Room{id} {

}

RockChamber::~RockChamber() {

}

/**
 * @brief RockChamber::description
 * @return std::string description detailing type of chamber
 */
std::string RockChamber::description () const {
    return "A dark, gloomy chamber. (Rock Chamber) \n";
}


}
