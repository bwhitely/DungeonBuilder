#include "game.h"
#include <Core/menuinterface.h>
#include <Core/Dungeon/Common/onewaydoor.h>

namespace core {

// initialize instance to a nullptr
Game* Game::theInstance{nullptr};

Game::Game() {

}

Game::~Game()
{
    // reset theBuilder unique ptr
    theBuilder.reset();
    theInstance = nullptr;
}

Game* Game::instance() {
    // check if nullptr, if it is make a new Game object
    if (theInstance == nullptr){
        theInstance = new Game();
    }
    return theInstance;
}

void Game::setDungeonType(std::unique_ptr<dungeon::DungeonLevelBuilder> builder)
{
    // move pointer
    theBuilder = std::move(builder);
}



void Game::createExampleLevel() {

}

void Game::createRandomLevel(std::string name, int width, int height) {
    theBuilder->BuildDungeonLevel(name, width, height);
}

void Game::displayLevel(std::ostream &display) const {


}

double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}

}

