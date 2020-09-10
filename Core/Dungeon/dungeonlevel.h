#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H
#include <string>
#include <vector>
#include <Core/Dungeon/room.h>

namespace core::dungeon {
class DungeonLevel {
  public:
    DungeonLevel() = delete;
    virtual ~DungeonLevel() = default;

    DungeonLevel(std::string name, int width, int height);
    bool addRoom(Room* room);
    Room* retrieveRoom(int id);
    int width() const;
    int height() const;
    int numberOfRooms() const;
    std::string name() const;
    virtual std::string description() = 0;
    std::vector<std::string>* display();
protected:
    std::vector<Room*> _rooms;
};
}

#endif // DUNGEONLEVEL_H
