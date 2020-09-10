#include "basicdungeonlevelbuilder.h"
#include <Core/Dungeon/Basic/rockchamber.h>

namespace core::dungeon::basic {

BasicDungeonLevelBuilder::BasicDungeonLevelBuilder() {

}

void BasicDungeonLevelBuilder::BuildDungeonLevel(std::string name, int width, int height) {
    _name = name;
    _width = width;
    _height = height;
}

void BasicDungeonLevelBuilder::buildItem(Room* room) {

}

Room* BasicDungeonLevelBuilder::buildRoom(int id) {
    core::dungeon::basic::RockChamber* r = new core::dungeon::basic::RockChamber(id);
    return r;
    delete r;
}

void BasicDungeonLevelBuilder::buildCreature(Room* room) {

}

DungeonLevel* BasicDungeonLevelBuilder::getDungeonLevel() {

}

void BasicDungeonLevelBuilder::buildExit(Room* room, Direction direction) {

}

void BasicDungeonLevelBuilder::buildEntrance(Room* room, Direction direction) {

}

void BasicDungeonLevelBuilder::buildDoorway(Room* origin, Room* destination, Direction direction, MoveConstraints constraints) {

}


}
