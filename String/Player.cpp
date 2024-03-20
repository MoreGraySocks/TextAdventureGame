#include "Player.h"
#include "Game.h"

using namespace std;

Player::Player(){
	spells[0].str = "flame";
	spells[1].str = "frost";
	spells[2].str = "shrink";

	hasMeat = false;
	hasPotato = false;
	hasSoup = false;
	hasTorch = false;
}

void Player::Description() {}

void Player::ExecuteCommand(int command, String input) {
	Game game;
	switch (command) {
		case NORTH:
			if (game.m_rooms[m_position.x][m_position.y].canMoveNorth) {
				m_position.y++;
			}
			break;
		case EAST:
			if (game.m_rooms[m_position.x][m_position.y].canMoveNorth) {
				m_position.x++;
			}
			break;
		case WEST:
			if (game.m_rooms[m_position.x][m_position.y].canMoveNorth) {
				m_position.x--;
			}
			break;
		case SOUTH:
			if (game.m_rooms[m_position.x][m_position.y].canMoveNorth) {
				m_position.y--;
			}
			break;
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

