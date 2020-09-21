#include "doorway.h"

namespace core::dungeon {

Doorway::Doorway(Direction direction) : RoomEdge(direction) {

}

Doorway::~Doorway() {

}

bool Doorway::isPassage() const {

}

char Doorway::displayCharacter() const {

}

std::string Doorway::description() const {

}

bool Doorway::isEntrance() {

}

bool Doorway::isExit() {

}

void Doorway::connect(Doorway* opposite) {

}


}
