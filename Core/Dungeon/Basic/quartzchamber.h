#ifndef QUARTZCHAMBER_H
#define QUARTZCHAMBER_H
#include <Core/Dungeon/room.h>

namespace core::dungeon::basic {
/**
 * @brief The QuartzChamber class - Type of Room that only exists in BasicDungeonLevel.
 */
class QuartzChamber : public Room {
  public:
    QuartzChamber(const int id);
    virtual ~QuartzChamber();

    std::string description() const override;
};
}


#endif // QUARTZCHAMBER_H
