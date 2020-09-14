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

    // first row
    theBuilder->buildDoorway(rooms.at(0), rooms.at(1), East, None);
    theBuilder->buildDoorway(rooms.at(1), rooms.at(2), East, OriginImpassable|DestinationImpassable);
    theBuilder->buildDoorway(rooms.at(0), rooms.at(3), South, OriginImpassable);
    theBuilder->buildDoorway(rooms.at(1), rooms.at(4), South, None);
    theBuilder->buildDoorway(rooms.at(2), rooms.at(5), South, DestinationLocked);
    // second row
    theBuilder->buildDoorway(rooms.at(3), rooms.at(4), East, OriginImpassable);
    theBuilder->buildDoorway(rooms.at(4), rooms.at(5), East, None);
    theBuilder->buildDoorway(rooms.at(3), rooms.at(6), South, OriginImpassable|DestinationImpassable);
    theBuilder->buildDoorway(rooms.at(4), rooms.at(7), South, None);
    // third row
    theBuilder->buildDoorway(rooms.at(6), rooms.at(7), East, DestinationLocked|OriginLocked);
    theBuilder->buildDoorway(rooms.at(7), rooms.at(8), East, None);

    theBuilder->buildEntrance(rooms.at(0), North);

    theBuilder->buildExit(rooms.at(8), East);

    theBuilder->buildItem(rooms.at(2));
    theBuilder->buildItem(rooms.at(4));
    theBuilder->buildItem(rooms.at(6));

    theBuilder->buildCreature(rooms.at(2));
    theBuilder->buildCreature(rooms.at(4));
    theBuilder->buildCreature(rooms.at(8));
    rooms.at(8)->creature().setBoss();

    theBuilder->getDungeonLevel();

}

void Game::createRandomLevel(std::string name, int width, int height) {

}

void Game::displayLevel(std::ostream& display) const {

}

double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}

}

