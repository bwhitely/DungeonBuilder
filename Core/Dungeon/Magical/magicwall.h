#ifndef MAGICWALL_H
#define MAGICWALL_H
#include <Core/Dungeon/wall.h>

namespace core::dungeon::magical {
/**
 * @brief The MagicWall class - Derived from Wall. Can only exist in MagicalDungeonLevels.
 */
class MagicWall : public Wall {
  public:
    MagicWall() = delete;
    MagicWall(Wall& other) = delete;

    MagicWall(Direction direction);
    virtual ~MagicWall();

    bool isPassage() const override;
    char displayCharacter() const override;
    std::string description() const override;
    void printDirection() const;

};
}


#endif // MAGICWALL_H
