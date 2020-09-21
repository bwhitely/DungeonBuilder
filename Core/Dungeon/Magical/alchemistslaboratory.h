#ifndef ALCHEMISTSLABORATORY_H
#define ALCHEMISTSLABORATORY_H
#include <Core/Dungeon/room.h>

namespace core::dungeon::magical {
/**
 * @brief The AlchemistsLaboratory class - MagicalDungeonLevel specific type of Room.
 */
class AlchemistsLaboratory : public Room {
  public:
    AlchemistsLaboratory(int id);
    virtual ~AlchemistsLaboratory();

    std::string description() const override;
};
}


#endif // ALCHEMISTSLABORATORY_H
