#ifndef OPENDOORWAY_H
#define OPENDOORWAY_H
#include <Core/Dungeon/doorway.h>

namespace core::dungeon::common {
class OpenDoorway : public Doorway
{
public:
    OpenDoorway(Direction direction);
    virtual ~OpenDoorway();
    void connect(Doorway* opposite);
    bool isEntrance();
    bool isExit();
    bool isPassage() const override;
    char displayCharacter() const override;
    std::string description() const override;
protected:
    Direction _direction;
    Doorway* _opposite;
    bool _entrance;
    bool _exit;
};
}

//class RaspberryPie : public Pie
//{
//public:
//  RaspberryPie();
//  virtual ~RaspberryPie();
//  RaspberryPie(const RaspberryPie &) = default;
//  std::string description() const override; // see comments in 'applepie.h'
//  std::string tastiness() const override;
//};

#endif // OPENDOORWAY_H
