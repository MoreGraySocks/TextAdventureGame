#include "Torch.h"

void Torch::Description() {
	if (m_isLit) {
		std::cout << "The torch's glow is comforting" << std::endl;
	}
	else {
		std::cout << "I wonder if I could light this" << std::endl;
	}
}

void Torch::Use() {
	if (m_isLit == false) {
		std::cout << "You used your " << RED << "Flame" << RESET_COLOUR << " spell to light the torch" << std::endl;
		m_isLit = true;
	}


}
