#include <iostream>
#include <Core/menuinterface.h>

using namespace std;

int main()
{
    MenuInterface m = MenuInterface(cout, cin);
    m.displayWelcome("Ben Whitely", "Assignment 1: Dungeon Builder");
    m.run();

    return 0;
}
