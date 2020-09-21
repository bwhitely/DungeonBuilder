#ifndef BLOCKEDDOORWAY_H
#define BLOCKEDDOORWAY_H
#include <Core/Dungeon/doorway.h>

namespace core::dungeon::common {
/**
 * @brief The BlockedDoorWay class - Type of Doorway that exists in a RoomEdge. Does not allow travel.
 */
class BlockedDoorWay : public Doorway {
  public:
    BlockedDoorWay(Direction direction);
    virtual ~BlockedDoorWay();
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


#endif // BLOCKEDDOORWAY_H
