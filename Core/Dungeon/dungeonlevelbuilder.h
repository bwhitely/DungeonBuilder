#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H
#include <string>
#include <Core/Dungeon/room.h>
#include <Core/Dungeon/dungeonlevel.h>

// unsigned enum
enum MoveConstraints : unsigned {None = 0, OriginImpassable = 1, DestinationImpassable = 2, OriginLocked = 4, DestinationLocked = 8};

namespace core::dungeon {
// forward declaration of Room
class Room;
class DungeonLevelBuilder {
  public:
    virtual ~DungeonLevelBuilder();
    virtual void BuildDungeonLevel(std::string name, int width, int height);
    virtual Room* buildRoom(int id);
    virtual void buildDoorway(Room* origin, Room* destination, Direction direction, MoveConstraints constraints);
    virtual void buildEntrance(Room* room, Direction direction);
    virtual void buildExit(Room* room, Direction direction);
    virtual void buildItem(Room*);
    virtual void buildCreature(Room*);
    virtual DungeonLevel* getDungeonLevel();
protected:
    DungeonLevelBuilder();
    std::string _name;
    int _width;
    int _height;
    Room* _origin;
};
}


#endif // DUNGEONLEVELBUILDER_H
