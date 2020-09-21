#ifndef GAME_H
#define GAME_H
#include <Core/Dungeon/dungeonlevelbuilder.h>
#include <string>
#include <random>
#include <ctime>
#include <memory>
#include <Core/Dungeon/dungeonlevel.h>

namespace core {

class Game {
  public:
    // deleting defaults
    Game(const Game& other) = delete;
    Game& operator=(const Game&) = delete;
    ~Game();

    // returns a pointer of the instance
    static Game* instance();

    void setDungeonType(std::unique_ptr<dungeon::DungeonLevelBuilder> builder);
    void createExampleLevel();
    void createRandomLevel(std::string name, int width, int height);
    void displayLevel(std::ostream &display) const;
    double randomDouble();
    std::string roomDescription(int id);
    std::string levelDescription();

  private:
    // unique ptr to builder
    std::unique_ptr<dungeon::DungeonLevelBuilder> theBuilder;
    // private constructor to prevent instancing
    Game();
    // static instance of Game
    static Game* theInstance;

    std::shared_ptr<core::dungeon::DungeonLevel> __level;
    core::dungeon::DungeonLevel* _level;
    std::mt19937 _randomGenerator{uint32_t(time(nullptr))};
    std::uniform_real_distribution<double> _realDistribution{0.0, 1.0};
};
}



#endif // GAME_H
