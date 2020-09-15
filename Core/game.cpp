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
    // move unique ptr
    theBuilder = std::move(builder);
}

void Game::createExampleLevel() {
    // rooms vector
    std::vector<core::dungeon::Room*> rooms;

    if (theBuilder) {
        theBuilder->BuildDungeonLevel("Example Level", 3, 3);
    }

    // create and push 9 rooms
    for (int i = 1; i < 10; i++){
        rooms.push_back(theBuilder->buildRoom(i));
    }
//asdas
    // first row
    theBuilder->buildDoorway(rooms.at(0), rooms.at(1), East, None); // rm 1 East
    theBuilder->buildDoorway(rooms.at(0), rooms.at(3), South, OriginImpassable); // rm 1 south
    theBuilder->buildDoorway(rooms.at(1), rooms.at(2), East, OriginImpassable | DestinationImpassable); // rm 2 east
    theBuilder->buildDoorway(rooms.at(1), rooms.at(4), South, None); // rm 2 south
    theBuilder->buildDoorway(rooms.at(2), rooms.at(5), South, DestinationLocked); // rm 3 south
    // second row
    theBuilder->buildDoorway(rooms.at(3), rooms.at(4), East, OriginImpassable); // rm 4 east
    theBuilder->buildDoorway(rooms.at(3), rooms.at(6), South, OriginImpassable | DestinationImpassable); // rm 4 south
    theBuilder->buildDoorway(rooms.at(4), rooms.at(7), South, None); // rm 5 east
    theBuilder->buildDoorway(rooms.at(4), rooms.at(5), East, None); // rm 5 south

    // third row
    theBuilder->buildDoorway(rooms.at(6), rooms.at(7), East, DestinationLocked | OriginLocked);
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

    _level = theBuilder->getDungeonLevel();

    std::cout << "Successful" << std::endl;

}

void Game::createRandomLevel(std::string name, int width, int height) {

}

void Game::displayLevel(std::ostream& display) const {

    // Display row 1
    for (int i = 0; i < 6; i++) {
        display << theBuilder->getDungeonLevel()->retrieveRoom(0)->display().at(i) +
                theBuilder->getDungeonLevel()->retrieveRoom(1)->display().at(i) +
                theBuilder->getDungeonLevel()->retrieveRoom(2)->display().at(i)
                << std::endl;
    }

    // Display row 2
    for (int i = 0; i < 6; i++) {
        display << theBuilder->getDungeonLevel()->retrieveRoom(3)->display().at(i) +
                theBuilder->getDungeonLevel()->retrieveRoom(4)->display().at(i) +
                theBuilder->getDungeonLevel()->retrieveRoom(5)->display().at(i)
                << std::endl;
    }

    // Display row 3
    for (int i = 0; i < 6; i++) {
        display << theBuilder->getDungeonLevel()->retrieveRoom(6)->display().at(i) +
                theBuilder->getDungeonLevel()->retrieveRoom(7)->display().at(i) +
                theBuilder->getDungeonLevel()->retrieveRoom(8)->display().at(i)
                << std::endl;
    }
}

double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}

}

