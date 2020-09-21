#include "dungeonlevel.h"
#include <iostream>

namespace core::dungeon {

DungeonLevel::~DungeonLevel() {

}

DungeonLevel::DungeonLevel(std::string name, int width, int height) {
    _name = name;
    _width = width;
    _height = height;
}

/**
 * @brief DungeonLevel::addRoom - Adds room param to shared_ptr vector of Rooms
 * @param room
 * @return true
 */
bool DungeonLevel::addRoom(const std::shared_ptr<Room> room) {
    _rooms.emplace_back(room);
    return true;
}

/**
 * @brief DungeonLevel::retrieveRoom - Returns room from Room vector adhering to specified id
 * @param id
 * @return shared_ptr<Room>
 */
std::shared_ptr<Room> DungeonLevel::retrieveRoom(int id) {
    //return std::make_shared<Room>(rooms.at(id));
    return _rooms.at(id - 1);
}

/**
 * @brief DungeonLevel::width - Returns width
 * @return int
 */
int DungeonLevel::width() const {
    return _width;
}

/**
 * @brief DungeonLevel::height - Returns height
 * @return int
 */
int DungeonLevel::height() const {
    return _height;
}

/**
 * @brief DungeonLevel::numberOfRooms - Returns number of Rooms in vector
 * @return int
 */
int DungeonLevel::numberOfRooms() const {
    return _rooms.size();
}

/**
 * @brief DungeonLevel::name - Returns name of room
 * @return std::string
 */
std::string DungeonLevel::name() const {
    return _name;
}

/**
 * @brief DungeonLevel::display - A visual representation of the DungeonLevel.
 * @return std::vector<std::string>>
 */
std::vector<std::string> DungeonLevel::display() {
    // This is a very average algorithm and is a bit janky, but it works.

    // Vector of Rooms, size equal to height (num of Rows of Rooms) * 6 (6 rows in each Room vector)
    std::vector<std::string> level (_height * 6);

    int rowDone = 0;
    int room = 1;
    int at = 0;

    // rowDone increments each time a row is complete, so while it's less than the _height (aka. the rows) it will continue to loop
    while (rowDone < _height) {
        // for loop for the width (aka the cols)
        for (int i = 1; i < _width + 1; i++) {
            // this copies an entire room at a time to the level vector
            level.at(at) += retrieveRoom(room)->display().at(0);
            level.at(at + 1) += retrieveRoom(room)->display().at(1);
            level.at(at + 2) += retrieveRoom(room)->display().at(2);
            level.at(at + 3) += retrieveRoom(room)->display().at(3);
            level.at(at + 4) += retrieveRoom(room)->display().at(4);
            level.at(at + 5) += retrieveRoom(room)->display().at(5);
            // increment room variable, so next loop will be currentRoom+1 until this row of Rooms is complete
            room++;
        }

        // add 6 each iteration (as 6 is the number of rows in the vector, this allows me to move to the next row of Rooms in the vector
        at += 6;
        // row finished, increment
        rowDone++;
    }

    return level;
}

}

