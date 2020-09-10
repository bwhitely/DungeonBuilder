#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H
#include <string>

namespace core::creatures {

}

class AbstractCreature
{
public:
    AbstractCreature() = delete;
    AbstractCreature(std::string name);
    virtual AbstractCreature clone();
    std::string name();
    char displayCharacter();
protected:
    std::string _name;
    char _char;
};

#endif // ABSTRACTCREATURE_H
