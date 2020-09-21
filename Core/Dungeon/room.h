#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <Core/Items/item.h>
#include <Core/Creatures/abstractcreature.h>
#include <Core/Creatures/monster.h>
#include <vector>

// enum
enum Direction : unsigned {North, South, East, West};

namespace core::dungeon {
class RoomEdge;

class Room {
  public:
    Room() = delete;
    Room(const Room& room) = delete;
    Room(const int id);
    virtual ~Room();

    // overloading << as mentioned in specs
    friend std::ostream& operator<<(std::ostream& out, const std::shared_ptr<Room> room);

    virtual std::string description() const = 0;
    std::vector<std::string> display();
    int id() const;
    core::items::Item& item() const;
    void setItem(std::unique_ptr<core::items::Item> newItem);

    AbstractCreature& creature() const;
    void setCreature(std::unique_ptr<AbstractCreature> creature);

    // get/set room edges
    void setNorth(RoomEdge*);
    RoomEdge* getNorth() const;
    void setEast(RoomEdge*);
    RoomEdge* getEast() const;
    void setSouth(RoomEdge*);
    RoomEdge* getSouth() const;
    void setWest(RoomEdge*);
    RoomEdge* getWest() const;

    void setEdge(Direction direction, std::string dwayType);
    RoomEdge* getEdge(Direction direction) const;

    void setEntrance() const;
    void setExit() const;

    int numberOfEdges() const;
    bool hasCreature() const;
    bool hasItem() const;

    bool containsExit() const;
    bool containsEntrance() const;

  protected:
    const int _id;
    std::unique_ptr<items::Item> _item;
    std::unique_ptr<AbstractCreature> _creature;
    RoomEdge* _north;
    RoomEdge* _east;
    RoomEdge* _south;
    RoomEdge* _west;

};
}

#endif // ROOM_H
