#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H
#include <iostream>
#include <string>
#include <set>

namespace core {

/**
 * @brief The MenuInterface class - Where the user can interact with the program
 */
class MenuInterface {
  public:
    // pass by ref MenuInterface streams
    MenuInterface(std::ostream& display, std::istream& input);
    // since displayWelcome strings would never be modified, im using const along with pass by ref
    void displayWelcome(std::string const& author, std::string const& title) const;
    void run();
    // Using sets for input validation because I have in the past
    void completeSets();
    // Had to split the menus into sub-menus otherwise it's too messy
    void mainMenu();
    void describeMenu();
    void explorationMenu();
  private:
    std::ostream& _display;
    std::istream& _input;
    // input sets
    std::set<char> mainMenuOptions;
    std::set<char> describeMenuOptions;
    std::set<char> explorationMenuOptions;
};
}


#endif // MENUINTERFACE_H
