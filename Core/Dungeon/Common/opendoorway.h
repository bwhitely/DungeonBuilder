#ifndef OPENDOORWAY_H
#define OPENDOORWAY_H
#include <Core/Dungeon/doorway.h>

namespace core::dungeon::common {
/**
 * @brief The OpenDoorway class - Type of Doorway that can exist in RoomEdges. Allows free travel between Rooms.
 */
class OpenDoorway : public Doorway {
  public:
    OpenDoorway(Direction direction);
    virtual ~OpenDoorway();
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

#endif // OPENDOORWAY_H
