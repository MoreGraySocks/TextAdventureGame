#include "Potato.h"

Potato::Potato() {}
Potato::~Potato() {}

void Potato::Description(bool hasPotato) {
	if (hasPotato) {
		std::cout << "A slightly green potato, it should still be edible" << std::endl;
	}
	else {
		std::cout << "A sack of potatoes sits against the wall" << std::endl;
	}
}

void Potato::Use(Room rooms[MAP_WIDTH][MAP_HEIGHT], Point2D playerPos) {

}

void Potato::AddToPot() {

}