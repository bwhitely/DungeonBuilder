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
    if (theInstance == nullptr)
        theInstance = new Game();

    return theInstance;
}

void Game::setDungeonType(std::unique_ptr<dungeon::DungeonLevelBuilder> builder) {
    // move unique ptr
    theBuilder = std::move(builder);
}

void Game::createExampleLevel() {
    // rooms vector
    std::vector<core::dungeon::Room*> rooms;

    // nullptr check
    if (theBuilder)
        theBuilder->BuildDungeonLevel("Example Level", 3, 3);

    // Create 9 Rooms and push to Room vector
    for (int i = 1; i < 10; i++)
        rooms.push_back(theBuilder->buildRoom(i));

    // First row of Rooms
    theBuilder->buildDoorway(rooms.at(0), rooms.at(1), East, None);
    theBuilder->buildDoorway(rooms.at(0), rooms.at(3), South, OriginImpassable);
    theBuilder->buildDoorway(rooms.at(1), rooms.at(2), East, OriginImpassable | DestinationImpassable);
    theBuilder->buildDoorway(rooms.at(1), rooms.at(4), South, None);
    theBuilder->buildDoorway(rooms.at(2), rooms.at(5), South, DestinationLocked);
    // Second row of Rooms
    theBuilder->buildDoorway(rooms.at(3), rooms.at(4), East, OriginImpassable);
    theBuilder->buildDoorway(rooms.at(3), rooms.at(6), South, OriginImpassable | DestinationImpassable);
    theBuilder->buildDoorway(rooms.at(4), rooms.at(7), South, None);
    theBuilder->buildDoorway(rooms.at(4), rooms.at(5), East, None);
    // Third row of Rooms
    theBuilder->buildDoorway(rooms.at(6), rooms.at(7), East, DestinationLocked | OriginLocked);
    theBuilder->buildDoorway(rooms.at(7), rooms.at(8), East, None);
    // Build Entrance
    theBuilder->buildEntrance(rooms.at(0), North);
    // Build Exit
    theBuilder->buildExit(rooms.at(8), East);
    // Build Items
    theBuilder->buildItem(rooms.at(2));
    theBuilder->buildItem(rooms.at(4));
    theBuilder->buildItem(rooms.at(6));
    // Build Creatures
    theBuilder->buildCreature(rooms.at(2));
    theBuilder->buildCreature(rooms.at(4));
    theBuilder->buildCreature(rooms.at(8));
    // Return Completed Dungeon Level
    _level = theBuilder->getDungeonLevel();

}

void Game::createRandomLevel(std::string name, int width, int height) {
    // Rooms vector
    std::vector<core::dungeon::Room*> rooms;

    // check for nullptr
    if (theBuilder)
        theBuilder->BuildDungeonLevel(name, width, height);

    // Number of rooms
    int numRooms = width * height;

    /** If dungeon is 1x1 */
    // Get a random double
    double rand = randomDouble();

    // If dungeon has a size of 1, I made a 50/50 chance for the entrance / exits to spawn on an RoomEdge
    if (width == 1 && height == 1) {
        // Build room
        rooms.push_back(theBuilder->buildRoom(numRooms));

        // Build Entrance
        if (rand <= 0.5)
            theBuilder->buildEntrance(rooms.at(0), North);
        else
            theBuilder->buildEntrance(rooms.at(0), West);

        // Build Exit
        if (rand > 0.5)
            theBuilder->buildExit(rooms.at(0), South);
        else
            theBuilder->buildExit(rooms.at(0), East);

        // Add creature to room and flag as boss
        theBuilder->buildCreature(rooms.at(0));
        rooms.at(0)->creature().setBoss();
        // 1x1 so has to be an item, the probability of weapon or consumable is handled in the buildItem() itself
        theBuilder->buildItem(rooms.at(0));

        /** If dungeon is != 1x1 */
    } else {
        /** Build Rooms */
        // Create 9 Rooms and push to Room vector
        for (int i = 1; i < numRooms + 1; i++)
            rooms.push_back(theBuilder->buildRoom(i));

        /** Build Items & Creatures */
        // Randomly add items/creatures
        for (int i = 0; i < theBuilder->getDungeonLevel()->numberOfRooms(); i++) {
            // Get a random double each loop to ensure there's actually a 25%/35% chance for items/creatures to spawn each loop
            double r = randomDouble();

            // If it's the last room, set creature. Will be made a Boss inside buildCreature()
            if (i == theBuilder->getDungeonLevel()->numberOfRooms() - 1)
                theBuilder->buildCreature(rooms.at(i));
            // 25% for creature AND not in first room
            else if (r < 0.25 && i != 0)
                theBuilder->buildCreature(rooms.at(i));

            // reroll again for item, otherwise every room with an item would also have a monster
            r = randomDouble();

            // 35% for item AND not in first room OR last room (so I can have explicit logic for last room)
            if (r < 0.35 && i != 0 && i != theBuilder->getDungeonLevel()->numberOfRooms() - 1)
                theBuilder->buildItem(rooms.at(i));
            // In last room, add an Item
            else if (i == theBuilder->getDungeonLevel()->numberOfRooms() - 1)
                theBuilder->buildItem(rooms.at(i));
        }

        /** Build Doorways */


        /** Build Entrance */
        // Get a double for probability purposes
        double r = randomDouble();

        // If the row has 3 or 4 Rooms
        if (width == 3 || width == 4) {
            // Entrance can only be on far left or far right, so 50% chance of either
            if (r < 0.5) {
                // Far left North
                if (r <= 0.166)
                    theBuilder->buildEntrance(rooms.at(0), North);
                // Far left + 1 North
                else if (r > 0.166 && r < 0.33)

                    // If width is 4, place in 3rd Room in row
                    if (width == 4)
                        theBuilder->buildEntrance(rooms.at(2), North);
                // Width is 3, place entrance in middle Room
                    else
                        theBuilder->buildEntrance(rooms.at(1), North);
                // > 0.33, place in far left West
                else
                    theBuilder->buildEntrance(rooms.at(0), West);
            } else {
                // Far right room so entrance can only spawn on North or East side. 50% chance of either.
                if (r < 0.75 && r > 0.5)
                    theBuilder->buildEntrance(rooms.at(width - 1), North);
                else if (r >= 0.75)
                    theBuilder->buildEntrance(rooms.at(width - 1), East);
            }
        }
        /** Only difference between the above and below code is the room.at() index */
        // Row has 2 Rooms
        else if (width == 2) {
            // Entrance can only be on far left or far right, so 50% chance of either
            if (r < 0.5) {
                // Far left room, so entrance can only spawn on North or West side. 50% chance of either.
                if (r < 0.25)
                    theBuilder->buildEntrance(rooms.at(0), North);
                else if (r >= 0.25)
                    theBuilder->buildEntrance(rooms.at(0), West);
            } else {
                // Far right room so entrance can only spawn on North or East side. 50% chance of either.
                if (r < 0.75)
                    theBuilder->buildEntrance(rooms.at(1), North);
                else if (r >= 0.75)
                    theBuilder->buildEntrance(rooms.at(1), East);
            }
        }

        /** Build Exit */
        // Get the last row of Rooms index
        int lastRow = (height * width) - width;

        // Get a new double for this
        r = randomDouble();

        // Row has 3 or 4 Rooms
        if (width == 3 || width == 4) {

            // Far left side and/or Room at far left + 1
            if (r < 0.5) {
                if (r < 0.166)
                    // Far left south
                    theBuilder->buildExit(rooms.at(lastRow), South);
                else if (r >= 0.166 && r < 0.33)

                    // If width is 4, place exit on 3rd Room in Row
                    if (width == 4)
                        theBuilder->buildExit(rooms.at(lastRow + 2), South);
                // Place exit in middle Room in row
                    else
                        theBuilder->buildExit(rooms.at(lastRow + 1), South);
                // Far left West
                else
                    theBuilder->buildExit(rooms.at(lastRow), West);

                // Far right side and/or Room at far right - 1
            } else if (r >= 0.5) {
                if (r < 0.667)
                    // Far right East
                    theBuilder->buildExit(rooms.at(numRooms - 1), East);
                else if (r >= 0.667 && r < 0.833)

                    // If there's 4 rooms, place this exit at the 3rd Room in the Row
                    if (width == 4)
                        theBuilder->buildExit(rooms.at(numRooms - 2), South);
                // Otherwise there's 3 rooms, place in middle Room in row
                    else
                        theBuilder->buildExit(rooms.at(numRooms - 1), South);
                // > 0.833, place in Far right South
                else
                    theBuilder->buildExit(rooms.at(numRooms - 1), South);

            }
        } else if (width == 2) {
            // Place an exit is either left or right side
            if (r < 0.5) {
                // Left side
                if (r < 0.25)
                    theBuilder->buildExit(rooms.at(lastRow), South);
                else
                    theBuilder->buildExit(rooms.at(lastRow), West);

                // Right side
            } else if (r >= 0.5) {
                if (r < 0.75)
                    theBuilder->buildExit(rooms.at(numRooms - 1), South);
                else
                    theBuilder->buildExit(rooms.at(numRooms - 1), East);
            }
        }
    }

    _level = theBuilder->getDungeonLevel();
}

void Game::displayLevel(std::ostream& display) const {

    // Get vector and size of vector
    std::vector<std::string> stringVec = theBuilder->getDungeonLevel()->display();
    int x = stringVec.size();

    // Loop over DungeonLevel vector and display each row
    for (int i = 0; i < x; i++) {
        display << stringVec.at(i) << std::endl;
    }
}

double Game::randomDouble() {
    return _realDistribution(_randomGenerator);
}

}

