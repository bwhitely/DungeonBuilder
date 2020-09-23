#ifndef DOORWAY_H
#define DOORWAY_H
#include <Core/Dungeon/roomedge.h>

namespace core::dungeon {
/**
 * @brief The Doorway class - Derived from RoomEdge, and has 4 further derived Doorway types.
 */
class Doorway : public RoomEdge {
  public:
    Doorway() = delete;
    Doorway(Direction direction);
    virtual ~Doorway();
    // override from RoomEdge
    virtual bool isPassage() const override;
    virtual char displayCharacter() const override;
    virtual std::string description() const override;

    virtual bool isEntrance();
    virtual bool isExit();
    virtual void connect(Doorway* opposite);
  protected:
    Doorway* _opposite;
    Direction _direction;
    bool _entrance;
    bool _exit;
};
}

#endif // DOORWAY_H
