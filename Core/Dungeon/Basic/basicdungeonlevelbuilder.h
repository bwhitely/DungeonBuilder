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
    void buildItem(Room*) override;
    Room* buildRoom(int id) override;
    void buildCreature(Room*) override;
    DungeonLevel* getDungeonLevel() override;
    void buildExit(Room* room, Direction direction) override;
    void buildEntrance(Room* room, Direction direction) override;
    void buildDoorway(Room* origin, Room* destination, Direction direction, MoveConstraints constraints) override;
    int getRandomNumber(int min, int max);
  private:
    BasicDungeonLevel* level;
//    std::vector<AbstractCreature*> creatures;
    std::vector<std::unique_ptr<AbstractCreature>> creatures;
    std::vector<std::unique_ptr<core::items::Item>> items;
};
}


#endif // BASICDUNGEONLEVELBUILDER_H
