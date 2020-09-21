#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H
#include <string>
#include <vector>
#include <Core/Dungeon/room.h>

namespace core::dungeon {
class DungeonLevel {
  public:
    DungeonLevel() = delete;
    virtual ~DungeonLevel();

    DungeonLevel(std::string name, int width, int height);
    virtual bool addRoom(std::shared_ptr<Room> room);
    virtual std::shared_ptr<Room> retrieveRoom(int id);
    virtual int width() const;
    virtual int height() const;
    virtual int numberOfRooms() const;
    virtual std::string name() const;
    virtual std::string description() = 0;
    virtual std::vector<std::string> display();
protected:
    std::vector<std::shared_ptr<Room>> _rooms;
    std::string _name;
    int _width;
    int _height;
};
}

#endif // DUNGEONLEVEL_H
