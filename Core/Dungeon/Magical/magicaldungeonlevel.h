#ifndef MAGICALDUNGEONLEVEL_H
#define MAGICALDUNGEONLEVEL_H
#include <Core/Dungeon/dungeonlevel.h>

namespace core::dungeon::magical {
/**
 * @brief The MagicalDungeonLevel class - MagicalDungeonLevelBuilder creates a MagicalDungeonLevel, and MagicalDungeonLevel implements the DungeonLevel interface.
 */
class MagicalDungeonLevel : public DungeonLevel {
  public:
    MagicalDungeonLevel(std::string name, int width, int height);
    virtual ~MagicalDungeonLevel();
    std::string description() override;
};
}


#endif // MAGICALDUNGEONLEVEL_H
