#ifndef LOCKEDDOOR_H
#define LOCKEDDOOR_H
#include <Core/Dungeon/doorway.h>

namespace core::dungeon::common {
class LockedDoor : public Doorway {
  public:
    LockedDoor(Direction direction);
    virtual ~LockedDoor();
    void connect(Doorway* opposite);
    bool isEntrance() const;
    bool isExit() const;
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
