#ifndef DOORWAY_H
#define DOORWAY_H
#include <Core/Dungeon/roomedge.h>

namespace core::dungeon {
class Doorway : public RoomEdge
{
public:
    Doorway();
    void connect(Doorway opposite);
    bool isEntrance();
    bool isExit();
};
}

#endif // DOORWAY_H
