#ifndef ITEM_H
#define ITEM_H
#include <string>

namespace core::items {
class Item
{
public:
    Item(std::string name);
    Item clone();
    std::string name();
    char displayCharacter();
};
}


#endif // ITEM_H
