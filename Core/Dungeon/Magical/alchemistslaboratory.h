#ifndef ALCHEMISTSLABORATORY_H
#define ALCHEMISTSLABORATORY_H
#include <Core/Dungeon/room.h>

namespace core::dungeon::magical {
class AlchemistsLaboratory : public Room {
  public:
    AlchemistsLaboratory(int id);
    virtual ~AlchemistsLaboratory();

    std::string description() const override;
};
}


#endif // ALCHEMISTSLABORATORY_H
