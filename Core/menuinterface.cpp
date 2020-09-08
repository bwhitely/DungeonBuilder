#include "menuinterface.h"

namespace core {
MenuInterface::MenuInterface(std::ostream& display, std::istream& input) {
//    string s;
//    // If input fails
//    if (input.fail()){
//        input.clear();
//    } else {
//        input >> s;
//    }
//    if (s == "g"){
//        display << "What would you like to do?\n"
//                << "(g)enerate the example level\n"
//                << "(r)andom dungeon level"
//                << "(q)uit";
//    }
}

void MenuInterface::displayWelcome(const std::string& author, const std::string& title) const {
    std::cout << "Welcome to: " + title << std::endl
         << "Developed by " + author << std::endl
         << "COMP 3023 Software Development with C++" << std::endl;
}

void MenuInterface::run() {

}
}
