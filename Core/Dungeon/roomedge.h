#ifndef ROOMEDGE_H
#define ROOMEDGE_H
#include <string>

namespace core::dungeon {
class RoomEdge
{
public:
    RoomEdge();
    std::string description();
    char displayCharacter();
    bool isPassage();
};

}

#endif // ROOMEDGE_H
