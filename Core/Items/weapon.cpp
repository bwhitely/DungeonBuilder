#include "weapon.h"

namespace core::items {

Weapon::Weapon(std::string name) : Item{name} {
    _name = name;
}

Weapon::~Weapon() {

}

/**
 * @brief Weapon::clone - Deep copy of weapon
 * @return
 */
std::unique_ptr<Item> Weapon::clone() {
    // return unique ptr clone
    return std::make_unique<Weapon>(*this);
}
}
