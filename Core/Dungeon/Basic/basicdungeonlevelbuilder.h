#ifndef BASICDUNGEONLEVELBUILDER_H
#define BASICDUNGEONLEVELBUILDER_H
#include <Core/Dungeon/dungeonlevelbuilder.h>
#include <memory>
#include <Core/Dungeon/Basic/basicdungeonlevel.h>
#include <Core/Items/consumeable.h>
#include <Core/Items/weapon.h>

namespace core::dungeon::basic {
class BasicDungeonLevelBuilder : public DungeonLevelBuilder {
  public:
    BasicDungeonLevelBuilder();
    virtual ~BasicDungeonLevelBuilder();
    void BuildDungeonLevel(std::string name, int width, int height) override;
    void buildItem(std::shared_ptr<Room>) override;
    std::shared_ptr<Room> buildRoom(int id) override;
    void buildCreature(std::shared_ptr<Room>) override;
    std::shared_ptr<DungeonLevel> getDungeonLevel() override;
    void buildExit(std::shared_ptr<Room> room, Direction direction) override;
    void buildEntrance(std::shared_ptr<Room> room, Direction direction) override;
    void buildDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination, Direction direction, MoveConstraints constraints) override;
    int getRandomNumber(int min, int max);

    Direction getOpposite(Direction direction);
  private:
    std::shared_ptr<BasicDungeonLevel> _level;
    std::vector<std::unique_ptr<AbstractCreature>> creatures;
    std::vector<std::unique_ptr<core::items::Item>> items;
};
}


#endif // BASICDUNGEONLEVELBUILDER_H
