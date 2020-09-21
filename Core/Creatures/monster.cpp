#include "monster.h"

using namespace core::creatures;

Monster::Monster(std::string name) : AbstractCreature{name} {
    _name = name;
    _isBoss = false;
}

Monster::~Monster() {
}

/**
 * @brief Monster::clone
 * @return deep unique_ptr copy of creature
 */
std::unique_ptr<AbstractCreature> Monster::clone() {
    return std::make_unique<Monster>(*this);
}



