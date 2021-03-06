#include "consumeable.h"

namespace core::items {

Consumeable::Consumeable(std::string name) : Item{name} {
    _name = name;
}

Consumeable::~Consumeable() {

}

/**
 * @brief Consumeable::clone - Deep copy of Consumeable
 * @return
 */
std::unique_ptr<Item> Consumeable::clone() {
    // return unique ptr clone
    return std::make_unique<Consumeable>(*this);
}

}
