#include "game.h"
#include <Core/menuinterface.h>

namespace core {
Game::Game(){
    theInstance = new Game;
}

Game *Game::instance()
{
    if (!theInstance){
        theInstance = new Game;
        return theInstance;
    }
    return theInstance;
}

void Game::setDungeonType(core::dungeon::DungeonLevelBuilder) {

}

void Game::createExampleLevel() {

}

void Game::createRandomLevel(std::string& name, int& with, int& height) {

}

void Game::displayLevel() const {
    std::cout << "DISPLAY LEVEL" << std::endl;
}

double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}

}

