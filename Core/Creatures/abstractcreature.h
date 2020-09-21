#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H
#include <string>
#include <memory>

namespace core::creatures {

}

class AbstractCreature {
  public:
    AbstractCreature() = delete;
    AbstractCreature(std::string name);

    virtual ~AbstractCreature();
    virtual std::unique_ptr<AbstractCreature> clone() = 0;
    virtual std::string name() const;
    virtual char displayCharacter() const;
    void setBoss();
    bool isBoss() const;
  protected:
    bool _isBoss;
    std::string _name;
    char _char;
};

#endif // ABSTRACTCREATURE_H
