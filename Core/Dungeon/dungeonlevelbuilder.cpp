#include "dungeonlevelbuilder.h"

namespace core::dungeon {

DungeonLevelBuilder::DungeonLevelBuilder() {

}

DungeonLevelBuilder::~DungeonLevelBuilder() {

}

void DungeonLevelBuilder::BuildDungeonLevel(std::string name, int width, int height) {

}

Room* DungeonLevelBuilder::buildRoom(int id) {

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

