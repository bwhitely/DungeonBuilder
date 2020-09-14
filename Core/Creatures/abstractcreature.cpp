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
}
