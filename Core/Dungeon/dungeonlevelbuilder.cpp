#include "dungeonlevelbuilder.h"
#include <iostream>

namespace core::dungeon {

DungeonLevelBuilder::DungeonLevelBuilder() {

}

DungeonLevelBuilder::~DungeonLevelBuilder() {

}

void DungeonLevelBuilder::BuildDungeonLevel(std::string name, int width, int height) {

}

Room* DungeonLevelBuilder::buildRoom(int id) {
    std::cout << "please dont" << std::endl;
}

void DungeonLevelBuilder::buildDoorway(Room* origin, Room* destination, Direction direction, MoveConstraints constraints) {

}

void DungeonLevelBuilder::buildEntrance(Room* room, Direction direction) {

}

void DungeonLevelBuilder::buildExit(Room* room, Direction direction) {

}

void DungeonLevelBuilder::buildItem(Room*) {

}

void DungeonLevelBuilder::buildCreature(Room*) {

}

DungeonLevel* DungeonLevelBuilder::getDungeonLevel() {

}

}

// Overloaded | and & as per assignment specs
MoveConstraints operator|(const MoveConstraints &origin, const MoveConstraints &destination)
{
    return static_cast<MoveConstraints>(static_cast<unsigned>(origin) | static_cast<unsigned>(destination));
}

MoveConstraints operator&(const MoveConstraints &origin, const MoveConstraints &destination)
{
    return static_cast<MoveConstraints>(static_cast<unsigned>(origin) & static_cast<unsigned>(destination));
}
