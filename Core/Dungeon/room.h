#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <Core/Items/item.h>
#include <Core/Creatures/abstractcreature.h>
#include <Core/Creatures/monster.h>
#include <vector>

namespace core::dungeon {
class RoomEdge;

class Room {
  public:
    Room() = delete;
    Room(const Room& room) = delete;
    Room(const int id);
    // virtual destructor
    virtual ~Room();

    // overloading << as mentioned in specs
    friend std::ostream& operator<<(std::ostream& out, const Room& room);

    virtual std::string description() const = 0;
    std::vector<std::string> display();
    int id() const;
    core::items::Item* item();
    void setItem(core::items::Item* newItem);
    AbstractCreature* creature();
    void setCreature(AbstractCreature* newCreature);

    // get/set room edges
    void setNorth(RoomEdge*);
    RoomEdge* getNorth();
    void setEast(RoomEdge*);
    RoomEdge* getEast();
    void setSouth(RoomEdge*);
    RoomEdge* getSouth();
    void setWest(RoomEdge*);
    RoomEdge* getWest();

    void setEntrance() const;
    void setExit() const;

protected:
    const int _id;
    core::items::Item* _item;
    AbstractCreature* _creature;
    RoomEdge* _north;
    RoomEdge* _east;
    RoomEdge* _south;
    RoomEdge* _west;

};
}
// enum
enum Direction : unsigned {North, South, East, West};

#endif // ROOM_H
