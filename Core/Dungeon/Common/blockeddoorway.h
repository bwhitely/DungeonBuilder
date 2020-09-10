#ifndef BLOCKEDDOORWAY_H
#define BLOCKEDDOORWAY_H
#include <Core/Dungeon/doorway.h>

namespace core::dungeon::common {
class BlockedDoorWay : public Doorway
{
public:
    BlockedDoorWay(Direction direction, bool entrance, bool exit);
    virtual ~BlockedDoorWay();
    void connect(Doorway* opposite);
    bool isEntrance();
    bool isExit();
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
