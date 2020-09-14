#include "monster.h"

using namespace core::creatures;

Monster::Monster(std::string name) : AbstractCreature{name} {
    _name = name;
}

Monster::~Monster() {

}

std::unique_ptr<AbstractCreature> Monster::clone() {
    // deep copy
    return std::make_unique<Monster>(*this);
}



