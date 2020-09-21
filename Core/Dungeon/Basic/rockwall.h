#ifndef ROCKWALL_H
#define ROCKWALL_H
#include <Core/Dungeon/wall.h>

namespace core::dungeon::basic {

/**
 * @brief The RockWall class - Type of Wall that only exists in a BasicDungeonLevel.
 */
class RockWall : public Wall {
  public:
    RockWall() = delete;
    RockWall(Wall& other) = delete;

    RockWall(Direction direction);
    virtual ~RockWall();

    bool isPassage() const override;
    char displayCharacter() const override;
    std::string description() const override;

    void printDirection() const;

};
}

#endif // ROCKWALL_H
