#include "menuinterface.h"
#include <vector>
#include <set>
#include <iostream>
#include <istream>
#include <Core/game.h>
#include <Core/Dungeon/Basic/basicdungeonlevelbuilder.h>
#include <Core/Dungeon/Magical/magicaldungeonlevelbuilder.h>
#include <Core/Dungeon/Basic/basicdungeonlevel.h>

using namespace std;
using namespace core;
using namespace core::dungeon;
using namespace core::dungeon::basic;
using namespace core::dungeon::magical;
using namespace core::items;
using namespace core::creatures;
namespace core {

// declare Director once here so I don't need to create multiple due scoping from separating the menu options
Game* game = game->instance();
std::string levelName;
int rows;
int cols;
bool exampleLevel = false;

MenuInterface::MenuInterface(std::ostream&, std::istream&) : _display(std::cout), _input(std::cin),
    mainMenuOptions{}, describeMenuOptions{}, explorationMenuOptions{} {

}

void MenuInterface::displayWelcome(const std::string& author, const std::string& title) const {
    _display << "Welcome to: " + title << std::endl
             << "Developed by " + author << std::endl
             << "COMP 3023 Software Development with C++\n" << std::endl;
}

/**
 * @brief MenuInterface::run - Fills in menu option sets and starts program
 */
void MenuInterface::run() {
    // Fill in sets and run menu
    completeSets();
    mainMenu();
}

/**
 * @brief MenuInterface::completeSets - Fills 3 sets (1 for each type of menu) with available valid input options
 */
void MenuInterface::completeSets() {
    // add options for main Menu
    mainMenuOptions.insert('q');
    mainMenuOptions.insert('r');
    mainMenuOptions.insert('g');

    // add options for describe/view menu
    describeMenuOptions.insert('d');
    describeMenuOptions.insert('v');
    describeMenuOptions.insert('r');

    // add options for exploration menu
    explorationMenuOptions.insert('d');
    explorationMenuOptions.insert('r');
}

/**
 * @brief MenuInterface::mainMenu - Manu menu interface
 * Has input validation, creates randomLevel with specified input as parameters if user asks, creates exampleLevel if user asks, can also display the DungeonLevel,
 * Show level description (name, size, type) and a specific Room's description.
 */
void MenuInterface::mainMenu() {

    _display << "What would you like to do?\n"
             << "  (g)enerate the example level\n"
             << "  (r)andom dungeon level\n"
             << "  (q)uit\n";

    char in;
    _input >> in;

    // failed input
    if (_input.fail()) {
        _display << "fail\n" << std::endl;
        _input.ignore();
        mainMenu();

        // Example level
    } else if (in == 'g' && mainMenuOptions.count('g') == 1) {
        _display << "Creating Example Dungeon Level..." << std::endl;

        std::unique_ptr<BasicDungeonLevelBuilder> bd{new BasicDungeonLevelBuilder()};
        game->setDungeonType(std::move(bd));

        game->createExampleLevel();
        exampleLevel = true;


        _display << "Dungeon level created!\n" << std::endl;
        describeMenu();

        // Random level
    } else if (in == 'r' && mainMenuOptions.count('r') == 1) {
        char dungType;
        bool withinRange = false;
        bool validLevelType = false;

        while (true) {
            _display << "What would you like to call this level?" << std::endl;
            _input.ignore();
            std::getline(_input, levelName);

            // Empty name
            if (levelName == "") {
                _display << "Name cannot be empty." << std::endl;
                _input.clear();
                _input.sync();
            } else {
                break;
            }
        }

        // Dungeon row selection
        while (!withinRange) {
            _display << "How many rows in " + levelName << "?" << std::endl;
            _input >> rows;

            // failed input
            if (_input.fail()) {
                _display << "\nIncorrect input type. Please use an Integer.\n";
                _input.clear();
                _input.sync();
            }

            else if ((rows >= 1) && (rows <= 4) && !_input.fail()) {
                break;
            } else if (!(_input.fail())) {
                _display << "\nRow not within range. Please enter (1-4) inclusive.\n";
            }
        }

        // Dungeon column selection
        while (!withinRange) {
            _display << "How many columns in " + levelName << "?" << std::endl;
            _input >> cols;

            // failed input
            if (_input.fail()) {
                _display << "\nIncorrect input type. Please use an Integer.\n";
                _input.clear();
                _input.sync();
            }

            if ((cols >= 1) && (cols <= 4) && !_input.fail()) {
                break;
            } else if (!(_input.fail())) {
                _display << "\nRow not within range. Please enter (1-4) inclusive.\n";
            }
        }


        // Dungeon level type selection
        while (!validLevelType) {
            _display << "What type of dungeon level is it? (b)asic or (m)agical?" << std::endl;
            _input >> dungType;

            if (dungType != 'b' && dungType != 'm') {
                _display << "\nInvalid type selection. Please select only 'b' or 'm'\n";
                _input.ignore();
            } else {
                validLevelType = true;
            }

            if (dungType == 'b') {
                exampleLevel = false;
                // New builder
                std::unique_ptr<BasicDungeonLevelBuilder> bd{new BasicDungeonLevelBuilder()};
                _display << "\nCreating " + levelName + "..." << std::endl;

                // Move pointer & create level
                game->setDungeonType(std::move(bd));
                game->createRandomLevel(levelName, rows, cols);

                _display << "Dungeon level created!\n" << std::endl;
                // call menu
                describeMenu();

            } else if (dungType == 'm') {
                exampleLevel = false;
                // New builder
                std::unique_ptr<MagicalDungeonLevelBuilder> md{new MagicalDungeonLevelBuilder()};

                _display << "\nCreating " + levelName + "..." << std::endl;

                // move pointer & create level
                game->setDungeonType(std::move(md));
                game->createRandomLevel(levelName, rows, cols);

                _display << "Dungeon level created!\n" << std::endl;
                // call menu
                describeMenu();
            }
        }

        // Quit
    } else if (in == 'q' && mainMenuOptions.count('q') == 1) {
        _display << "Are you sure you want to quit? y/n" << std::endl;
        _input >> in;

        // Yes
        if (in == 'y') {
            _input.sync();
            _input.clear();
            _display << "Goodbye!" << std::endl;

            // No
        } else if (in == 'n') {
            _display << "\nTaking you back to main menu...\n" << std::endl;
            mainMenu();
        }
    } else if (mainMenuOptions.count(in) == 0) {
        _display << "Not a valid selection :^)\n" << std::endl;
        _display.flush();
        _input.sync();
        mainMenu();
    }

}

void MenuInterface::describeMenu() {

    _display << "What would you like to do?\n"
             << "  (d)escribe the dungeon level\n"
             << "  (v)iew the dungeon level\n"
             << "  (r)eturn to the main menu\n";

    char in;
    _input >> in;

    // failed input
    if (_input.fail()) {
        _display << "fail\n" << std::endl;
        _input.clear();

        // Describe dungeon level
    } else if (in == 'd' && describeMenuOptions.count('d') == 1) {
        _display << game->levelDescription() << std::endl;
        explorationMenu();
        // View dungeon level
    } else if (in == 'v' && describeMenuOptions.count('v') == 1) {
        game->displayLevel(_display);

        _display << "*Press Enter to continue*" << std::endl;
        _input.clear();
        _input.sync();
        _input.get();
        describeMenu();

        // Return to prev menu
    } else if (in == 'r' && describeMenuOptions.count('r') == 1) {
        _display << "\nReturning to main menu.\n\n";
        mainMenu();
        // invalid input
    } else if (describeMenuOptions.count(in) == 0) {
        _display << "Not a valid selection :^)\n" << std::endl;
        _input.sync();
        describeMenu();
    }

}

void MenuInterface::explorationMenu() {
    _display << "What would you like to do?\n"
             << "  (d)escribe a room\n"
             << "  (r)eturn to previous menu\n";
    char in;
    _input >> in;

    // failed input
    if (_input.fail()) {
        _input.clear();

        // Describe room
    } else if (in == 'd' && explorationMenuOptions.count('d') == 1) {
        int numRooms = cols * rows;
        int roomNo;

        if (exampleLevel) {
            _display << "Which room would you like to describe? (1-9)" << std::endl;
            _input >> roomNo;

            // input validation
            while (roomNo > 9 || roomNo < 1) {
                _display << "Please enter a room between 1 and 9.\n";
                _input >> roomNo;
            }
        } else {
            _display << "Which room would you like to describe? (1-" + std::to_string(numRooms) + ")"  << std::endl;
            _input >> roomNo;

            // input validation
            while (roomNo > numRooms || roomNo < 1) {
                _display << "Please enter a room between 1 and " + std::to_string(numRooms) + "\n";
                _input >> roomNo;
            }
        }

        // display specified room
        _display << game->roomDescription(roomNo) << std::endl;
        // recall menu
        describeMenu();

        // Return to prev menu
    } else if (in == 'r' && explorationMenuOptions.count('r') == 1) {
        // return to prev menu
        _input.sync();
        describeMenu();
    } else if (explorationMenuOptions.count(in) == 0) {
        // invalid input
        _display << "Not a valid selection :^)\n" << std::endl;
        _input.sync();
        explorationMenu();
    }

    // deleting game - not actually sure if this is needed because this should only execute once the program ends but
    // i used the new keyword so i will also use the delete keyword.
    delete game;
}
}
