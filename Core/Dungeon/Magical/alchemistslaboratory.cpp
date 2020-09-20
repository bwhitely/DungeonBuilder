#include "alchemistslaboratory.h"

namespace core::dungeon::magical{

AlchemistsLaboratory::AlchemistsLaboratory(int id): Room{id}
{

}

AlchemistsLaboratory::~AlchemistsLaboratory()
{

}

std::string AlchemistsLaboratory::description() const
{
    return "A room filled with potions and herbs. (Alchemists Laboratory)\n";
}

}

