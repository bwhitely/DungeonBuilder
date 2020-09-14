#include "monster.h"

using namespace core::creatures;

Monster::Monster(std::string name) : AbstractCreature{name} {
    _name = name;
}

Monster::~Monster() {

}

AbstractCreature Monster::clone() {

}

std::string Monster::name()
{
    return _name;
}

char Monster::displayCharacter()
{
    if (isBoss){
        return 'M' + '*';
    }
    return 'M';
}


