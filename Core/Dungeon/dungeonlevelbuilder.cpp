#include "dungeonlevelbuilder.h"
#include <iostream>

namespace core::dungeon {

DungeonLevelBuilder::DungeonLevelBuilder() {

}

DungeonLevelBuilder::~DungeonLevelBuilder() {

}

void DungeonLevelBuilder::BuildDungeonLevel(std::string name, int width, int height) {

}

std::shared_ptr<Room> DungeonLevelBuilder::buildRoom(int id) {

}

void DungeonLevelBuilder::buildDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destinmation, Direction direction, MoveConstraints constraints) {

}

void DungeonLevelBuilder::buildEntrance(std::shared_ptr<Room> room, Direction direction) {

}

void DungeonLevelBuilder::buildExit(std::shared_ptr<Room> room, Direction direction) {

}

void DungeonLevelBuilder::buildItem(std::shared_ptr<Room>) {

}

void DungeonLevelBuilder::buildCreature(std::shared_ptr<Room>) {

}

DungeonLevel* DungeonLevelBuilder::getDungeonLevel() {

}
}

/**
 * @brief operator | - Overloaded | for combining MoveConstraints
 * @param origin
 * @param destination
 * @return
 */
MoveConstraints operator|(const MoveConstraints& origin, const MoveConstraints& destination) {
    return static_cast<MoveConstraints>(static_cast<unsigned>(origin) | static_cast<unsigned>(destination));
}

/**
 * @brief operator & - Overloaded & for combinding MoveConstraints
 * @param origin
 * @param destination
 * @return
 */
MoveConstraints operator&(const MoveConstraints& origin, const MoveConstraints& destination) {
    return static_cast<MoveConstraints>(static_cast<unsigned>(origin) & static_cast<unsigned>(destination));
}

