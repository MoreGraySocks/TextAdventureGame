#include "Player.h"

using namespace std;

Player::Player(){
	spells[0].str = "flame";
	spells[1].str = "frost";
	spells[2].str = "shrink";

	hasMeat = false;
	hasPotato = false;
	hasSoup = false;
	hasTorch = false;

	torch = new Torch();
}

Player::~Player() {
	torch = nullptr;
	delete torch;
}

void Player::Description() {}

void Player::ExecuteCommand(int command, String input, Room rooms[MAP_WIDTH][MAP_HEIGHT]) {
	cout << RESET_COLOUR;
	switch (command) {
		case HELP:
			cout << "Commands:\nMove (cardinal direction): Moves the character\nUse (item/spell): Uses an item in your inventory" << endl;
			cout << "Pick up (item): Picks up an item in the current room\nLook at (item): Describes an item in your inventory or the room" << endl;
			cout << "Talk: Talks to the creature in the starting room\nQuit: Ends the game" << endl;
			cout << "Inventory: Lists the current items in your inventory\nSpellbook: Lists the spells in your spellbook" << endl;
			break;
		case NORTH:
			if (rooms[m_position.x][m_position.y].canMoveNorth) {
				m_position.y++;
			}
			else { cout << "You cannot move north from here" << endl; }
			break;
		case EAST:
			if (rooms[m_position.x][m_position.y].canMoveEast) {
				m_position.x++;
			}
			else { cout << "You cannot move east from here" << endl; }
			break;
		case WEST:
			if (rooms[m_position.x][m_position.y].canMoveWest) {
				m_position.x--;
			}
			else { cout << "You cannot move west from here" << endl; }
			break;
		case SOUTH:
			if (rooms[m_position.x][m_position.y].canMoveSouth) {
				m_position.y--;
			}
			else { cout << "You cannot move south from here" << endl; }
			break;
		case TORCH:
			if (hasTorch) {
				torch->Use(rooms, m_position);
			}
			break;
		case POTATO:
			if (hasPotato) {
				
			}
			break;
		case MEAT:
			if (hasMeat) {

			}
			break;
		case SOUP:
			if (hasSoup) {

			}
			break;
		case FLAME:
			break;
		case PICKUP:
			if (m_position.x == HALLWAY_NORTH.x && m_position.y == HALLWAY_NORTH.y && !hasTorch) {
				if (input.Find("torch") != -1) {
					cout << "You picked up the torch" << endl;
					hasTorch = true;
				}
			}
			else { cout << "There is nothing to pick up here" << endl; }
			break;
		case LOOKAT:
			if (input.Find("torch") != -1 || !hasTorch && input.Find("sconce") != -1 && m_position.x == HALLWAY_NORTH.x && m_position.y == HALLWAY_NORTH.y) {
				torch->Description(hasTorch);
			}
			if (input.Find("potato")!= -1 || !hasPotato && input.Find("sack") != -1 && m_position.x == PANTRY.x && m_position.y == PANTRY.y)
			break;
		case TALK:
			break;
		case INVENTORY:
			cout << "Inventory:" << endl;
			if (hasTorch) {
				cout << "Torch" << endl;
			}if (hasPotato) {
				cout << "Potato" << endl;
			}if (hasMeat) {
				cout << "Meat" << endl;
			}if (hasSoup) {
				cout << "Soup" << endl;
			}if (!hasTorch && !hasPotato && !hasMeat && !hasSoup) {
				cout << "You have nothing in your inventory" << endl;
			}
			break;
		case SPELLBOOK:
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

