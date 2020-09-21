#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <memory>

namespace core::items {
class Item
{
public:
    Item() = delete;
    Item(std::string name);
    virtual ~Item();

    virtual std::unique_ptr<Item> clone() = 0;

    std::string name() const;
    char displayCharacter() const;
protected:
    std::string _name;
};
}


#endif // ITEM_H
