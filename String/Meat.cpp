#include "Meat.h"

Meat::Meat() {}
Meat::~Meat() {}

void Meat::Description() {
	std::cout << "It looks a little grey... hopefully nothing a little seasoning won't fix" << std::endl;
}

bool Meat::Use(Room rooms[MAP_WIDTH][MAP_HEIGHT], Point2D playerPos) {
	if (rooms[KITCHEN.x][KITCHEN.y].cookpotLit && playerPos.x == KITCHEN.x && playerPos.y == KITCHEN.y) {
		std::cout << CYAN_ << "You added the meat to the pot" << RESET_COLOUR << std::endl;
		return true;
	}
	else { 
		std::cout << "This.. isn't useful right now" << std::endl;
		return false; 
	}
}