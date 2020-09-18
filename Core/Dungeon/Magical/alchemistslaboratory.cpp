#include "alchemistslaboratory.h"

namespace core::dungeon::magical{

AlchemistsLaboratory::AlchemistsLaboratory(int id): Room{id}
{

}

AlchemistsLaboratory::~AlchemistsLaboratory()
{
    delete this;
}

std::string AlchemistsLaboratory::description() const
{
    return "Alchemists Laboratory";
}

}

