#ifndef MAGICALDUNGEONLEVEL_H
#define MAGICALDUNGEONLEVEL_H
#include <Core/Dungeon/dungeonlevel.h>

namespace core::dungeon::magical {
class MagicalDungeonLevel : public DungeonLevel
{
public:
    MagicalDungeonLevel(std::string name, int width, int height);
    virtual ~MagicalDungeonLevel();
    std::string description() override;
};
}


#endif // MAGICALDUNGEONLEVEL_H
