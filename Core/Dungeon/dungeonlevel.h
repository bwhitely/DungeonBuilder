#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H
#include <string>
#include <Core/Dungeon/room.h>

namespace core::dungeon {
class DungeonLevel
{
public:
    DungeonLevel(std::string name, int width, int height);
    bool addRoom(Room room);
    Room retrieveRoom(int id);
    int width();
    int height();
    int numberOfRooms();
    std::string name();
    std::string description();
    //std::string[] display();
};
}

#endif // DUNGEONLEVEL_H
