#include "item.h"

namespace core::items {

Item::Item(std::string name){
    _name = name;
}

Item::~Item()
{

}

std::unique_ptr<Item> Item::clone()
{

}

/**
 * @brief Item::name - Gets name of Item
 * @return
 */
std::string Item::name() const
{
    return _name;
}

/**
 * @brief Item::displayCharacter - Gets char of Item
 * @return
 */
char Item::displayCharacter() const
{
    return 'L';
}

}


