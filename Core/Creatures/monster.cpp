#include "monster.h"

using namespace core::creatures;

Monster::Monster(std::string name) : AbstractCreature{name} {
    _name = name;
}

Monster::~Monster() {

}

AbstractCreature Monster::clone() {

}
