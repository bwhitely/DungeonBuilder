#ifndef ENCHANTEDLIBRARY_H
#define ENCHANTEDLIBRARY_H
#include <Core/Dungeon/room.h>

namespace core::dungeon::magical {
/**
 * @brief The EnchantedLibrary class - MagicalDungeonLevel specific type of Room
 */
class EnchantedLibrary : public Room {
  public:
    EnchantedLibrary(int id);
    virtual ~EnchantedLibrary();

    std::string description() const override;
};
}


#endif // ENCHANTEDLIBRARY_H
