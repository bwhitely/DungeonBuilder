#ifndef ROCKCHAMBER_H
#define ROCKCHAMBER_H
#include <Core/Dungeon/room.h>

namespace core::dungeon::basic {
class RockChamber : public Room {
  public:
    RockChamber(const int id);
    virtual ~RockChamber();

    std::string description() const override;
};
}


#endif // ROCKCHAMBER_H
