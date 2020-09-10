#ifndef ITEM_H
#define ITEM_H
#include <string>

namespace core::items {
class Item
{
public:
    Item() = delete;
    Item(std::string name);
    virtual ~Item();

    virtual Item clone();
    std::string name();
    char displayCharacter();
    void setChar(char c);
protected:
    std::string _name;
    char _char;
};
}


#endif // ITEM_H
