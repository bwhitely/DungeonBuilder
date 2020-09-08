#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <Core/Items/item.h>
#include <Core/Creatures/abstractcreature.h>
#include <Core/Creatures/monster.h>

namespace core::dungeon {
class Room
{
public:
    Room(int id);
    enum Direction {North, South, East, West};
    void display(std::string);
    int id();
    core::items::Item item();
    void setItem(core::items::Item newItem);
    //core::creatures::AbstractCreature creature();
    //void setCreature(core::creatures::AbstractCreature newCreature);
};
}


#endif // ROOM_H
