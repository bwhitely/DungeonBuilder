#include "game.h"
#include <Core/menuinterface.h>

namespace core {

Game* Game::theInstance = 0;

Game::Game() {

}

Game* Game::instance() {
    if (theInstance == 0){
        theInstance = new Game();
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

}

double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}

}

