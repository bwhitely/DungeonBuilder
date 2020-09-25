#ifndef ROOMEDGE_H
#define ROOMEDGE_H
#include <string>
#include <Core/Dungeon/room.h>

namespace core::dungeon {

class Room; // forward declaration

/**
 * @brief The RoomEdge class - Each Room has 4 RoomEdges. RoomEdge has child classes of Type Wall or Doorway.
 */
class RoomEdge {
  public:
    virtual ~RoomEdge();
    RoomEdge();
    RoomEdge(Direction _direction);
    RoomEdge(const RoomEdge& other) = delete;

    friend std::ostream& operator<<(std::ostream& out, const RoomEdge& roomEdge);

    virtual std::string description() const = 0;
    virtual char displayCharacter() const = 0;
    virtual bool isPassage() const = 0;

    const Direction& direction();

  protected:
    Direction _direction;
};

}
#endif // ROOMEDGE_H
