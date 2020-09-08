#include <iostream>
#include <Core/menuinterface.h>

using namespace std;

int main() {
    core::MenuInterface m = core::MenuInterface(cout, cin);
    m.displayWelcome("Ben Whitely", "Assignment 1: Dungeon Builder");
    // run main menu loop
    m.run();

    return 0;
}
