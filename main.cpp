#include <iostream>
#include <Core/menuinterface.h>
#include <Core/Dungeon/wall.h>
#include <Core/Dungeon/room.h>
#include <test.cpp>

using namespace std;

int main() {
    core::MenuInterface m = core::MenuInterface(cout, cin);
    m.displayWelcome("Ben Whitely", "Assignment 1: Dungeon Builder");
    // run main menu loop

    Test t;
    t.test();

    m.run();

    return 0;
}
