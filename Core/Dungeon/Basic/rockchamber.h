#ifndef ROCKCHAMBER_H
#define ROCKCHAMBER_H
#include <Core/Dungeon/room.h>

namespace core::dungeon::basic {
/**
 * @brief The RockChamber class - Type of Room that only exists inside BasicDungeonLevel.
 */
class RockChamber : public Room {
  public:
    RockChamber(const int id);
    virtual ~RockChamber();

    std::string description() const override;
};
}


#endif // ROCKCHAMBER_H
