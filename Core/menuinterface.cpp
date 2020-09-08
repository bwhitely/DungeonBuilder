#include "menuinterface.h"
#include <vector>
#include <set>
#include <iostream>
#include <istream>

namespace core {

MenuInterface::MenuInterface(std::ostream &display, std::istream &input) : _display(std::cout), _input(std::cin),
    mainMenuOptions{}, describeMenuOptions{}, explorationMenuOptions{}
{

}

void MenuInterface::displayWelcome(const std::string& author, const std::string& title) const {
    _display << "Welcome to: " + title << std::endl
         << "Developed by " + author << std::endl
         << "COMP 3023 Software Development with C++\n" << std::endl;
}

void MenuInterface::run() {
    completeSets();
    mainMenu();

}

void MenuInterface::completeSets()
{
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

void MenuInterface::mainMenu()
{
    while (true){
        _display << "What would you like to do?\n"
                 << "  (g)enerate the example level\n"
                 << "  (r)andom dungeon level\n"
                 << "  (q)uit\n";

        char in;
        _input >> in;
        while (true){

            // failed input
            if (_input.fail()){
                _display << "fail\n" << std::endl;
                _input.clear();
                in = 'y';
                break;

                // if input is 'g'
            } else if (in == 'r' && mainMenuOptions.count('g') == 1) {
                _display << "Creating Example Dungeon Level..." << std::endl
                         << "Dungeon level created!\n" << std::endl;
                break;

                // if input is 'r'
            } else if (in == 'g' && mainMenuOptions.count('r') == 1) {
                std::string levelName;
                int rows;
                int cols;
                char dungType;
                _display << "What would you like to call this level?" << std::endl;
                _input.ignore();
                std::getline(_input, levelName);
                _display << "How many rows in " + levelName << "?" << std::endl;
                _input >> rows;
                _display << "How many columns in " + levelName << "?" << std::endl;
                _input >> cols;
                _display << "What type of dungeon level is it? (b)asic or (m)agical?" << std::endl;
                _input >> dungType;
                _display << "\nCreating " + levelName + "..." << std::endl;
                _display << "Dungeon level created!\n" << std::endl;

                // transition to the describe menu
                describeMenu();

                // if input is 'q' (quit)
            } else if (in == 'q' && mainMenuOptions.count('q') == 1){
                _display << "Are you sure you want to quin? y/n" << std::endl;
                _input >> in;
                if (in == 'y'){
                    _display << "Goodbye!" << std::endl;
                    break;
                } else if (in == 'n'){
                    _display << "\nTaking you back to main menu...\n" << std::endl;
                    break;
                }
            }
        }
        // break again
        if (in == 'y'){
            break;
        }
    }
}

void MenuInterface::describeMenu()
{
    while(true){
        _display << "What would you like to do?\n"
                 << "  (d)escribe the dungeon level\n"
                 << "  (v)iew the dungeon level\n"
                 << "  (r)eturn to the main menu\n";

        char in;
        _input >> in;
        while (true){

            // failed input
            if (_input.fail()){
                _display << "fail\n" << std::endl;
                _input.clear();
                in = 'y';
                break;
            } else if (in == 'd' && describeMenuOptions.count('d') == 1) {

            } else if (in == 'v' && describeMenuOptions.count('v') == 1) {

            } else if (in == 'r' && describeMenuOptions.count('r') == 1) {
                mainMenu();
            }
        }
    }
}

void MenuInterface::explorationMenu()
{

}
}
