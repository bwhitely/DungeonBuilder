#ifndef WEAPON_H
#define WEAPON_H
#include <Core/Items/item.h>

namespace core::items {
class Weapon : public Item
{
public:
    Weapon(std::string name);
    virtual ~Weapon();
    std::unique_ptr<Item> clone() override;
};
}

#endif // WEAPON_H
