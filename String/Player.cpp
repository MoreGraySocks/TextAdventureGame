#include "Player.h"

using namespace std;

Player::Player(){
	spells[0].str = "flame";
	spells[1].str = "frost";
	spells[2].str = "shrink";
}

void Player::Description() {}

void Player::ExecuteCommand(int command, String input) {
	switch (command) {
		case NORTH:
		case EAST:
		case WEST:
		case SOUTH:
		case FIND_SPELL:
			if (SearchForSpell(input)) {
				cout << "That spell is in your spellbook" << endl;
			}
			else { cout << "That spell is not in your spellbook" << endl; }
			break;

	}
}

bool Player::SearchForSpell(String input) {
	input.ToLower();
	for (int i = 0; i < 3; i++) {
		if (input.Find(spells[i]) != -1) {
			return true;
		}
	}
	return false;
}

