#ifndef BASICDUNGEONLEVEL_H
#define BASICDUNGEONLEVEL_H
#include <Core/Dungeon/dungeonlevel.h>

namespace core::dungeon::basic {
class BasicDungeonLevel : public DungeonLevel
{
public:
    BasicDungeonLevel(std::string name, int width, int height);
    std::string description() override;

    bool addRoom(Room *room);
    Room* retrieveRoom(int);
    int width();
    int height();
    int numberOfRooms();
    std::string name();
    std::vector<std::string> display();
protected:
    std::string _name;
    int _width;
    int _height;
};
}


#endif // BASICDUNGEONLEVEL_H
