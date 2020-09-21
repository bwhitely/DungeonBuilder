#ifndef WALL_H
#define WALL_H
#include <Core/Dungeon/roomedge.h>

namespace core::dungeon {

/**
 * @brief The Wall class - Subclass of Room, is virtual itself and will have further derived classes.
 */
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
