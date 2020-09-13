#ifndef DOORWAY_H
#define DOORWAY_H
#include <Core/Dungeon/roomedge.h>

namespace core::dungeon {
class Doorway : public RoomEdge {
  public:
    Doorway() = delete;
    Doorway(Direction direction);
    virtual ~Doorway();
    // override from RoomEdge
    virtual bool isPassage() const override;
    virtual char displayCharacter() const override;
    virtual std::string description() const override;

    void connect(Doorway* opposite);
    bool isEntrance();
    bool isExit();
protected:
    Direction _direction;
    bool _entrance;
    bool _exit;
};
}

#endif // DOORWAY_H
