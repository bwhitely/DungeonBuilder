#include "enchantedlibrary.h"

namespace core::dungeon::magical{

EnchantedLibrary::EnchantedLibrary(int id) : Room{id}
{

}

EnchantedLibrary::~EnchantedLibrary()
{

}

std::string EnchantedLibrary::description() const
{
    return "Enchanted Library";
}

}

