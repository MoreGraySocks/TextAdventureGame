#include "Potato.h"

Potato::Potato() {}
Potato::~Potato() {}

void Potato::Description(bool hasPotato) {
	if (hasPotato) {
		std::cout << "A slightly green potato, it should still be edible" << std::endl;
	}
}

bool Potato::Use(Room rooms[MAP_WIDTH][MAP_HEIGHT], Point2D playerPos) {
	if (rooms[KITCHEN.x][KITCHEN.y].cookpotLit && playerPos.x == KITCHEN.x && playerPos.y == KITCHEN.y) {
		std::cout << CYAN_ << "You added the potato to the pot" << RESET_COLOUR << std::endl;
		return true;
	}
	else { 
		std::cout << CYAN_ << "You pull the potato out of your pocket..." << std::endl;
		std::cout << "You put the potato back in your pocket." << RESET_COLOUR << std::endl;
		return false; 
	}
}