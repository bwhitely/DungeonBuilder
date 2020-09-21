#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H
#include <string>
#include <Core/Dungeon/room.h>
#include <Core/Dungeon/dungeonlevel.h>

// unsigned enum
enum MoveConstraints : unsigned {None = 0, OriginImpassable = 1, DestinationImpassable = 2, OriginLocked = 4, DestinationLocked = 8};
MoveConstraints operator|(const MoveConstraints& origin, const MoveConstraints& destination);
MoveConstraints operator&(const MoveConstraints& origin, const MoveConstraints& destination);

namespace core::dungeon {

// forward declaration of Room
class Room;

/**
 * @brief The DungeonLevelBuilder class - Interface for the different types of DungeonLevelBuilders (bagic & magical)
 */
class DungeonLevelBuilder {
  public:
    DungeonLevelBuilder();
    virtual ~DungeonLevelBuilder();
    virtual void BuildDungeonLevel(std::string name, int width, int height);
    virtual std::shared_ptr<Room> buildRoom(int id);
    virtual void buildDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination, Direction direction, MoveConstraints constraints);
    virtual void buildEntrance(std::shared_ptr<Room> room, Direction direction);
    virtual void buildExit(std::shared_ptr<Room> room, Direction direction);
    virtual void buildItem(std::shared_ptr<Room>);
    virtual void buildCreature(std::shared_ptr<Room>);
    virtual std::shared_ptr<DungeonLevel> getDungeonLevel();
  protected:
    std::string _name;
    int _width;
    int _height;
};
}

#endif // DUNGEONLEVELBUILDER_H
