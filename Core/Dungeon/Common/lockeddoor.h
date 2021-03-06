#ifndef LOCKEDDOOR_H
#define LOCKEDDOOR_H
#include <Core/Dungeon/doorway.h>

namespace core::dungeon::common {
/**
 * @brief The LockedDoor class - Type of Doorway that exists in a RoomEdge. Is locked and does not allow travel through.
 */
class LockedDoor : public Doorway {
  public:
    LockedDoor(Direction direction);
    virtual ~LockedDoor();
    void connect(Doorway* opposite) override;
    bool isExit() override;
    bool isEntrance() override;
    bool isPassage() const override;
    char displayCharacter() const override;
    std::string description() const override;
  protected:
    Direction _direction;
    Doorway* _opposite;
    bool _entrance;
    bool _exit;
};
}


#endif // LOCKEDDOOR_H
