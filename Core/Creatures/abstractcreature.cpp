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

/**
 * @brief AbstractCreature::name - returns creature name
 * @return std::string name
 */
std::string AbstractCreature::name() const
{
    return _name;
}

/**
 * @brief AbstractCreature::displayCharacter - returns creature char
 * @return char
 */
char AbstractCreature::displayCharacter() const
{
    return 'M';
}

/**
 * @brief AbstractCreature::setBoss - Sets creature to boss
 */
void AbstractCreature::setBoss()
{
    _isBoss = true;
    _name = "Evil " + _name;
}

/**
 * @brief AbstractCreature::isBoss
 * @return bool, true if boss, false if not
 */
bool AbstractCreature::isBoss() const
{
    return _isBoss;
}
