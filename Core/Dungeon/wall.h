#ifndef WALL_H
#define WALL_H
#include <Core/Dungeon/roomedge.h>

namespace core::dungeon {
class Wall : public RoomEdge {
  public:
    Wall() = delete;
    Wall(Wall& other) = delete;
    Wall(Direction direction);
    virtual ~Wall() = default;

    virtual bool isPassage() const override = 0;
    virtual char displayCharacter() const override = 0;
    virtual std::string description() const override = 0;
};
}

#endif // WALL_H
