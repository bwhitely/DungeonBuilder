#include "roomedge.h"

namespace core::dungeon {

RoomEdge::~RoomEdge() {

}

RoomEdge::RoomEdge(Direction direction) : _direction{direction} {

}

/**
 * @brief operator << - Overloaded << operator
 * @param out
 * @param roomEdge
 * @return
 */
std::ostream& operator<<(std::ostream& out, const RoomEdge& roomEdge) {
    // return cout stream with description
    return out << roomEdge.description();
}

}
