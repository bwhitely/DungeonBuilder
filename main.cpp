#include <iostream>
#include <Core/menuinterface.h>
#include <Core/Dungeon/wall.h>
#include <Core/Dungeon/room.h>
#include <test.cpp>

using namespace std;

int main() {
    core::MenuInterface m = core::MenuInterface(cout, cin);
    m.displayWelcome("", "Assignment 1: Dungeon Builder");

    Test t;
    t.test();
    // run main menu loop
//    m.run();


    return 0;
}
