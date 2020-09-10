#include "abstractcreature.h"

using namespace core::creatures;

AbstractCreature::AbstractCreature(std::string name)
{
    _name = name;
}

AbstractCreature AbstractCreature::clone()
{

}

std::string AbstractCreature::name()
{
    return _name;
}

char AbstractCreature::displayCharacter()
{

}
