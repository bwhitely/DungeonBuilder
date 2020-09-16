#include "abstractcreature.h"
#include <iostream>

using namespace core::creatures;

AbstractCreature::AbstractCreature(std::string name)
{
    _name = name;
    _isBoss = false;
}

AbstractCreature::~AbstractCreature()
{

}

std::unique_ptr<AbstractCreature> AbstractCreature::clone()
{

}


std::string AbstractCreature::name()
{
    return _name;
}

char AbstractCreature::displayCharacter()
{
    return 'M';
}

void AbstractCreature::setBoss()
{
    _isBoss = true;
    _name = "Evil " + _name;
}

bool AbstractCreature::isBoss()
{
    return _isBoss;
}
