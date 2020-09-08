#ifndef GAME_H
#define GAME_H
#include <Core/Dungeon/dungeonlevelbuilder.h>
#include <string>
#include <random>
#include <ctime>

namespace core{

class Game {
  public:
    // returns a pointer of the instance
    static Game* instance();
    void setDungeonType(core::dungeon::DungeonLevelBuilder);
    void createExampleLevel();
    // pass by referencing these
    void createRandomLevel(std::string &name, int &width, int &height);
    void displayLevel();
    double randomDouble();
  private:
    Game();
    ~Game();
    // static instance of Game
    static Game theInstance;
    std::mt19937 _randomGenerator{uint32_t(time(nullptr))};
    std::uniform_real_distribution<double> _realDistribution{0.0, 1.0};
};
}


#endif // GAME_H
