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
    DungeonLevelBuilder();
};
}


#endif // DUNGEONLEVELBUILDER_H
