#ifndef GAME_H
#define GAME_H
#include <Core/Dungeon/dungeonlevelbuilder.h>
#include <string>
#include <random>
#include <ctime>

namespace core{

class Game {
  public:
    static Game instance();
    void setDungeonType(core::dungeon::DungeonLevelBuilder);
    void createExampleLevel();
    void createRandomLevel(std::string &name, int with, int height);
    void displayLevel();
    double randomDouble();
  private:
    Game();
    Game theInstance();
    std::mt19937 _randomGenerator{uint32_t(time(nullptr))};
    std::uniform_real_distribution<double> _realDistribution{0.0, 1.0};
};
}


#endif // GAME_H
