#include "abstractcreature.h"

using namespace core::creatures;

AbstractCreature::AbstractCreature(std::string name) : _name{name}, isBoss{false}
{
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
    if (isBoss){
        return 'M' + '*';
    }
    return 'M';
}

void AbstractCreature::setBoss()
{
    isBoss = true;
    _name = "Evil " + _name;
}
