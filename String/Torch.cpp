#include "Torch.h"

void Torch::Description(bool hasTorch) {
	if (hasTorch){
		if (m_isLit) {
			std::cout << "The torch's glow is comforting" << std::endl;
		}
		else {
			std::cout << "I wonder if I could light this" << std::endl;
		}
	}
	else {
		std::cout << "An unlit torch is sitting in an old sconce on the wall" << std::endl;
	}
}

void Torch::Use(Room rooms[MAP_WIDTH][MAP_HEIGHT], Point2D playerPos) {
	if (m_isLit == false) {
		std::cout << "You used your " << RED << "Flame" << RESET_COLOUR << " spell to light the torch" << std::endl;
		LightTorch();
	}
	else if (playerPos.x == KITCHEN.x && playerPos.y == KITCHEN.y) {
		std::cout << "You used your torch to light the cookpot" << std::endl;
		rooms[KITCHEN.x][KITCHEN.y].cookpotLit = true;
	}
	else {
		std::cout << "I don't think your torch would be useful here" << std::endl;
	}

}
