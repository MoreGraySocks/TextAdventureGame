#include "Soup.h"

bool Soup::CheckFinished() {
	if (m_addedPotato && m_addedMeat) {
		m_isFinished = true;
	}
	return m_isFinished;
}

void Soup::Description() {
	if (m_isFinished) {
		std::cout << "Great! I can give this to the monster now" << std::endl;
	}
	else {
		std::cout << "Hmmm, it seems like its missing something" << std::endl;
	}
}

bool Soup::Use(Room rooms[MAP_WIDTH][MAP_HEIGHT], Point2D playerPos) {

	if (CheckFinished()) {
		std::cout << CYAN_ << "You gave the soup to the creature" << RESET_COLOUR << std::endl;
		return true;
	}
	return false;
}
