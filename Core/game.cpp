#include "game.h"
#include <Core/menuinterface.h>

namespace core {
Game::Game() {

}

Game *Game::instance() {
    Game *g = new Game;
    return &theInstance;
}

void Game::setDungeonType(core::dungeon::DungeonLevelBuilder) {

}

void Game::createExampleLevel() {

}

void Game::createRandomLevel(std::string& name, int& with, int& height) {

}

void Game::displayLevel() {

}

double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}

}

