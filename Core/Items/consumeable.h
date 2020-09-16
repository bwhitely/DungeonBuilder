#ifndef CONSUMEABLE_H
#define CONSUMEABLE_H
#include <Core/Items/item.h>

namespace core::items {
class Consumeable : public Item
{
public:
    Consumeable(std::string);
    virtual ~Consumeable();
    std::unique_ptr<Item> clone() override;
};
}


#endif // CONSUMEABLE_H
