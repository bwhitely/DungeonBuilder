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

void Game::setDungeonType(core::dungeon::DungeonLevelBuilder* b) {
    builder = *b;
}

void Game::createExampleLevel() {

}

void Game::createRandomLevel(std::string name, int width, int height) {
    builder.BuildDungeonLevel(name, width, height);
}

void Game::displayLevel(std::ostream &display) const {
    for (int i = 0; i < this->theInstance->getBuilder()->getDungeonLevel()->numberOfRooms(); i++){
        this->theInstance->getBuilder()->getDungeonLevel()->retrieveRoom(i);

        display << "+----";
        //display << theInstance->getBuilder()->getDungeonLevel()->retrieveRoom(1)->description();
    }
}

double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}

dungeon::DungeonLevelBuilder* Game::getBuilder()
{
    return &builder;
}

}

