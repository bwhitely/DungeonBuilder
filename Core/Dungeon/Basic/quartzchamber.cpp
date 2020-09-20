#include "quartzchamber.h"
#include <iostream>

namespace core::dungeon::basic {

QuartzChamber::QuartzChamber(const int id) : Room{id}
{

}

QuartzChamber::~QuartzChamber()
{
}

std::string QuartzChamber::description() const
{
    return "A chamber that glitters like a thousand stars in the torchlight. (Quartz Chamber)\n";
}

}

