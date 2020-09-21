#ifndef MAGICALDUNGEONLEVELBUILDER_H
#define MAGICALDUNGEONLEVELBUILDER_H
#include <Core/Dungeon/dungeonlevelbuilder.h>
#include <Core/Dungeon/Magical/magicaldungeonlevel.h>
#include <Core/Items/consumeable.h>
#include <Core/Items/weapon.h>

namespace core::dungeon::magical {
/**
 * @brief The MagicalDungeonLevelBuilder class - Derived from DungeonLevelBuilder. Has different Items/Creatures/Room types and Walls than BasicDungeonLevelBuilder
 */
class MagicalDungeonLevelBuilder : public DungeonLevelBuilder {
  public:
    MagicalDungeonLevelBuilder();
    virtual ~MagicalDungeonLevelBuilder();
    void BuildDungeonLevel(std::string name, int width, int height) override;
    void buildItem(std::shared_ptr<Room> room) override;
    std::shared_ptr<Room> buildRoom(int id) override;
    void buildCreature(std::shared_ptr<Room> room) override;
    DungeonLevel* getDungeonLevel() override;
    void buildExit(std::shared_ptr<Room> room, Direction direction) override;
    void buildEntrance(std::shared_ptr<Room> room, Direction direction) override;
    void buildDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination, Direction direction, MoveConstraints constraints) override;
    int getRandomNumber(int min, int max);
    Direction getOpposite(Direction direction) const;
  private:
    DungeonLevel* level;
    std::vector<std::unique_ptr<AbstractCreature>> creatures;
    std::vector<std::unique_ptr<core::items::Item>> items;
};
}


#endif // MAGICALDUNGEONLEVELBUILDER_H
