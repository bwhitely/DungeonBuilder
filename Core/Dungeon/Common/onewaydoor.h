#ifndef ONEWAYDOOR_H
#define ONEWAYDOOR_H
#include <Core/Dungeon/doorway.h>

namespace core::dungeon::common {
/**
 * @brief The OneWayDoor class - Type of Doorway that exists in a RoomEdge. Can be the exit/entrance to the DungeonLevel. Can allow travel to a destination,
 * but will not allow travel back.
 */
class OneWayDoor : public Doorway {
  public:
    OneWayDoor(Direction direction, bool entrance, bool exit);
    virtual ~OneWayDoor();
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


#endif // ONEWAYDOOR_H
