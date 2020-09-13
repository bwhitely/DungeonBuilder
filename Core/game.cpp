#include "game.h"
#include <Core/menuinterface.h>
#include <Core/Dungeon/Common/onewaydoor.h>

namespace core {

// initialize instance to a nullptr
Game* Game::theInstance{nullptr};

Game::Game() {

}

Game::~Game() {
    // reset theBuilder unique ptr
    theBuilder = nullptr;
    theInstance = nullptr;
    std::cout << "Destroyed Game" << std::endl;
}

Game* Game::instance() {
    // check if nullptr, if it is make a new Game object
    if (theInstance == nullptr) {
        theInstance = new Game();
    }

    return theInstance;
}

void Game::setDungeonType(std::unique_ptr<dungeon::DungeonLevelBuilder> builder) {
    theBuilder = std::move(builder);

    if (theBuilder) {
        std::cout << "finished setting dungeon level" << std::endl;
    }

}

void Game::createExampleLevel() {
    // rooms vector
    std::vector<core::dungeon::Room*> rooms;

    if (theBuilder) {
        theBuilder->BuildDungeonLevel("Example Level", 3, 3);
    }

    // Build rooms
    core::dungeon::Room* r1 = theBuilder->buildRoom(1);
    rooms.push_back(r1);
    core::dungeon::Room* r2 = theBuilder->buildRoom(2);
    rooms.push_back(r2);
    core::dungeon::Room* r3 = theBuilder->buildRoom(3);
    rooms.push_back(r3);
    core::dungeon::Room* r4 = theBuilder->buildRoom(4);
    rooms.push_back(r4);
    core::dungeon::Room* r5 = theBuilder->buildRoom(5);
    rooms.push_back(r5);
    core::dungeon::Room* r6 = theBuilder->buildRoom(6);
    rooms.push_back(r6);
    core::dungeon::Room* r7 = theBuilder->buildRoom(7);
    rooms.push_back(r7);
    core::dungeon::Room* r8 = theBuilder->buildRoom(8);
    rooms.push_back(r8);
    core::dungeon::Room* r9 = theBuilder->buildRoom(9);
    rooms.push_back(r9);

}

void Game::createRandomLevel(std::string name, int width, int height) {
    // rooms vector
    std::vector<core::dungeon::Room*> rooms;

    if (theBuilder) {
        theBuilder->BuildDungeonLevel(name, width, height);
    }

    int size = width * height;

    for (int i = 0; i < size; i++) {
        theBuilder->buildRoom(i);
    }

    theBuilder->buildEntrance(theBuilder->getDungeonLevel()->retrieveRoom(1), Direction::North);
}

void Game::displayLevel(std::ostream& display) const {

}

double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}

}

