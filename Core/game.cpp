#include "game.h"
#include <Core/menuinterface.h>
#include <Core/Dungeon/Common/onewaydoor.h>

namespace core {

// initialize instance to a nullptr
Game* Game::theInstance{nullptr};

Game::Game() {

}

Game::~Game() {
    // reset theBuilder ptr
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

}

void Game::createExampleLevel() {
    // rooms vector
    std::vector<core::dungeon::Room*> rooms;

    if (theBuilder) {
        theBuilder->BuildDungeonLevel("Example Level", 3, 3);
    }

    // Build rooms
    rooms.push_back(theBuilder->buildRoom(1));
    rooms.push_back(theBuilder->buildRoom(2));
    rooms.push_back(theBuilder->buildRoom(3));
    rooms.push_back(theBuilder->buildRoom(4));
    rooms.push_back(theBuilder->buildRoom(5));
    rooms.push_back(theBuilder->buildRoom(6));
    rooms.push_back(theBuilder->buildRoom(7));
    rooms.push_back(theBuilder->buildRoom(8));
    rooms.push_back(theBuilder->buildRoom(9));

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

    // entrance
    theBuilder->buildEntrance(rooms.at(0), North);
    // exit
    theBuilder->buildExit(rooms.at(8), East);

    // items
    theBuilder->buildItem(rooms.at(2));
    theBuilder->buildItem(rooms.at(4));
    theBuilder->buildItem(rooms.at(6));

    // creatures
    theBuilder->buildCreature(rooms.at(2));
    theBuilder->buildCreature(rooms.at(4));
    theBuilder->buildCreature(rooms.at(8));
    rooms.at(8)->creature()->setBoss();

    std::cout << rooms.at(8)->creature()->name() << std::endl;
    std::cout << "Successful" << std::endl;

    // get dungeon level
//    theBuilder->getDungeonLevel();

}

void Game::createRandomLevel(std::string name, int width, int height) {

}

void Game::displayLevel(std::ostream& display) const {

}

double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}

}

