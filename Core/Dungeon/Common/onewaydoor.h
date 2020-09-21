#ifndef ONEWAYDOOR_H
#define ONEWAYDOOR_H
#include <Core/Dungeon/doorway.h>

namespace core::dungeon::common {
class OneWayDoor : public Doorway {
  public:
    OneWayDoor(Direction direction, bool entrance, bool exit);
    virtual ~OneWayDoor();
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


#endif // ONEWAYDOOR_H
