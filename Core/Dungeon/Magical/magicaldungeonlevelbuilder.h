#ifndef MAGICALDUNGEONLEVELBUILDER_H
#define MAGICALDUNGEONLEVELBUILDER_H
#include <Core/Dungeon/dungeonlevelbuilder.h>
#include <Core/Dungeon/Magical/magicaldungeonlevel.h>
#include <Core/Items/consumeable.h>
#include <Core/Items/weapon.h>

namespace core::dungeon::magical {
class MagicalDungeonLevelBuilder : public DungeonLevelBuilder
{
public:
    MagicalDungeonLevelBuilder();
    virtual ~MagicalDungeonLevelBuilder();
    void BuildDungeonLevel(std::string name, int width, int height) override;
    void buildItem(Room*) override;
    Room* buildRoom(int id) override;
    void buildCreature(Room*) override;
    DungeonLevel* getDungeonLevel() override;
    void buildExit(Room* room, Direction direction) override;
    void buildEntrance(Room* room, Direction direction) override;
    void buildDoorway(Room* origin, Room* destination, Direction direction, MoveConstraints constraints) override;
    int getRandomNumber(int min, int max);

    Direction getOpposite(Direction direction);
  private:
    MagicalDungeonLevel* level;
    std::vector<std::unique_ptr<AbstractCreature>> creatures;
    std::vector<std::unique_ptr<core::items::Item>> items;
};
}


#endif // MAGICALDUNGEONLEVELBUILDER_H
