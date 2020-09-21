#include "alchemistslaboratory.h"

namespace core::dungeon::magical {

AlchemistsLaboratory::AlchemistsLaboratory(int id): Room{id} {

}

AlchemistsLaboratory::~AlchemistsLaboratory() {

}

/**
 * @brief AlchemistsLaboratory::description
 * @return short std::string description of Room
 */
std::string AlchemistsLaboratory::description() const {
    return "A room filled with potions and herbs. (Alchemists Laboratory)\n";
}

}

