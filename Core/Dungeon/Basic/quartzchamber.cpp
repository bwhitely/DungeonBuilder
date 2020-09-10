#include "quartzchamber.h"

namespace core::dungeon::basic {

QuartzChamber::QuartzChamber(const int id) : Room{id}
{

}

QuartzChamber::~QuartzChamber()
{

}

std::string QuartzChamber::description() const
{
    return "Quartz Chamber";
}

}

