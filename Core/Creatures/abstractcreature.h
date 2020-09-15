#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H
#include <string>
#include <memory>

namespace core::creatures {

}

class AbstractCreature
{
public:
    AbstractCreature() = delete;
    AbstractCreature(std::string name);

    virtual ~AbstractCreature();
    virtual AbstractCreature* clone();
    virtual std::string name();
    virtual char displayCharacter();
    void setBoss();
    bool isBoss();
protected:
    bool _isBoss;
    std::string _name;
    char _char;
};

#endif // ABSTRACTCREATURE_H
