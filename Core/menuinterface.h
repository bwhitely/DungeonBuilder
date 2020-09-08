#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H
#include <iostream>
#include <string>

namespace core {

}

class MenuInterface
{
public:
    // pass by ref MenuInterface streams
    MenuInterface(std::ostream &display, std::istream &input);
    // since displayWelcome strubgs would never be modified, im using const along with pass by ref
    void displayWelcome(std::string const &author, std::string const &title) const;
    void run();
};

#endif // MENUINTERFACE_H
