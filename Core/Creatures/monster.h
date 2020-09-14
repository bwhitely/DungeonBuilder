#ifndef MONSTER_H
#define MONSTER_H
#include <Core/Creatures/abstractcreature.h>
#include <string>

namespace core::creatures {

}

class Monster : public AbstractCreature
{
public:
    Monster(std::string name);
    virtual ~Monster();
    std::unique_ptr<AbstractCreature> clone() override;

};

#endif // MONSTER_H
