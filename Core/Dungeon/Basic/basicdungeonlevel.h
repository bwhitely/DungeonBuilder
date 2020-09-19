#ifndef BASICDUNGEONLEVEL_H
#define BASICDUNGEONLEVEL_H
#include <Core/Dungeon/dungeonlevel.h>
#include <memory>

namespace core::dungeon::basic {
class BasicDungeonLevel : public DungeonLevel
{
public:
    BasicDungeonLevel(std::string name, int width, int height);
    virtual ~BasicDungeonLevel();
    std::string description() override;
};
}


#endif // BASICDUNGEONLEVEL_H
