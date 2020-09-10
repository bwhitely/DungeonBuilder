#ifndef ROOMEDGE_H
#define ROOMEDGE_H
#include <string>
#include <Core/Dungeon/room.h>

namespace core::dungeon {

class Room; // forward declaration

class RoomEdge {
  public:
    ~RoomEdge();
    RoomEdge();
    RoomEdge(Direction _direction);
    RoomEdge(const RoomEdge& other) = delete;

    friend std::ostream &operator<<(std::ostream& out, const RoomEdge& roomEdge);  //operator overload (<<) //operator overload (<<)

    virtual std::string description() const = 0;
    virtual char displayCharacter() const = 0;
    virtual bool isPassage() const = 0;
    const Direction& direction();

  protected:
    Direction _direction;
};

}
#endif // ROOMEDGE_H
