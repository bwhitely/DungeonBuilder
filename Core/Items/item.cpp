#include "item.h"

namespace core::items {

Item::Item(std::string name){
    _name = name;
}

Item::~Item()
{

}

Item Item::clone()
{

}

std::string Item::name()
{
    return _name;
}

char Item::displayCharacter()
{
    return _char;
}

void Item::setChar(char c)
{

}

}


