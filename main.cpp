#include <iostream>
#include <Core/menuinterface.h>
#include <Core/Dungeon/wall.h>
#include <Core/Dungeon/room.h>
#include <test.cpp>

using namespace std;

/**
  * @brief main executes the displayWelcome() and run() functions in menuinterface.cpp to display the welcome header and start the program.
  */
int main() {
    core::MenuInterface m = core::MenuInterface(cout, cin);
    m.displayWelcome("Ben Whitely", "Assignment 1: Dungeon Builder");

    Test t;
    t.test();

    m.run();

    return 0;
}
