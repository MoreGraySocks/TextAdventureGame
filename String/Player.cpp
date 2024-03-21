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
	hasKey = false;
	bedroomUnlocked = false;
	exitUnlocked = false;

	dialogue1 = false;
	dialogue2 = false;

	torch = new Torch();
	soup = new Soup();
	potato = new Potato();
	meat = new Meat();
}

Player::~Player() {
	torch = nullptr;
	delete torch;
	soup = nullptr;
	delete soup;
}

void Player::Description() {}

void Player::ExecuteCommand(int command, String input, Room rooms[MAP_WIDTH][MAP_HEIGHT]) {
	cout << RESET_COLOUR;
	switch (command) {
		case HELP:
			cout << YELLOW<<"Commands:\nMove (cardinal direction): Moves the character\nUse (item/spell): Uses an item in your inventory" << endl;
			cout << "Pick up (item): Picks up an item in the current room\nLook at (item): Describes an item in your inventory or the room" << endl;
			cout << "Talk: Talks to the creature in the starting room\nQuit: Ends the game" << endl;
			cout << "Inventory: Lists the current items in your inventory\nSpellbook: Lists the spells in your spellbook" <<RESET_COLOUR<< endl;
			break;
		case NORTH:
			if (rooms[m_position.x][m_position.y].canMoveNorth) {
				if (m_position.x == HALLWAY_NORTH.x && m_position.y == HALLWAY_NORTH.y) {
					if (!exitUnlocked) {
						cout << CYAN_ << "You try to push past the creature" << RESET_COLOUR << endl;
						cout << BLUE << "NUH UH, I'M NOT MOVIN'" << RESET_COLOUR << endl;
						cout << "The creature doesn't seem like he's going anywhere" << endl;
						break;
					}
				}
				m_position.y--;
			}
			else { cout << "You cannot move north from here" << endl; }
			break;
		case EAST:
			if (rooms[m_position.x][m_position.y].canMoveEast) {
				if (m_position.x == HALLWAY_SOUTH.x && m_position.y == HALLWAY_SOUTH.y) {
					if (!bedroomUnlocked) {
						if (!hasKey) {
							cout << CYAN_ << "You try the handle, but the door is locked" << RESET_COLOUR << endl;
							break;
						}
						else {
							cout << CYAN_ << "You unlock the door" << RESET_COLOUR << endl;
							bedroomUnlocked = true;
						}
					}
				}
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
				m_position.y++;
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
				if (potato->Use(rooms, m_position)) {
					soup->AddPotato();
					hasPotato = false;
				}
			}
			break;
		case MEAT:
			if (hasMeat) {
				if (meat->Use(rooms, m_position)) {
					soup->AddMeat();
					hasMeat = false;
				}
			}
			break;
		case SOUP:
			if (hasSoup && m_position.x == HALLWAY_NORTH.x && m_position.y == HALLWAY_NORTH.y) {
				if (soup->Use(rooms, m_position)) {
					cout << BLUE << "HEY, THANKS LITTLE GUY!" << RESET_COLOUR << endl;
					cout << "The yeti guy seems pleased as he stomps over to his bedroom, slurping his soup" << endl;
					cout << CYAN_ << "The exit is now unblocked" << RESET_COLOUR << endl;
					exitUnlocked = true;
				}

			}
			break;
		case KEY:
			if (hasKey && m_position.x == HALLWAY_SOUTH.x && m_position.y == HALLWAY_SOUTH.y) {
				cout << CYAN_ << "You unlock the door" << RESET_COLOUR << endl;
				bedroomUnlocked = true;
			}
			break;
		case FLAME:
			if (m_position.x == KITCHEN.x && m_position.y == KITCHEN.y && !rooms[KITCHEN.x][KITCHEN.y].cookpotLit) {
				std::cout << CYAN_ << "You used your "<<RED<<"Flame"<<RESET_COLOUR<<" spell to light the cookpot" << RESET_COLOUR << std::endl;
				rooms[KITCHEN.x][KITCHEN.y].cookpotLit = true;
			}
			break;
		case PICKUP:
			if (m_position.x == HALLWAY_SOUTH.x && m_position.y == HALLWAY_SOUTH.y && !hasTorch) {
				if (input.Find("torch") != -1) {
					cout << CYAN_ << "You picked up the torch" << RESET_COLOUR << endl;
					hasTorch = true;
				}
			}
			else if (m_position.x == PANTRY.x && m_position.y == PANTRY.y && !hasPotato) {
				if (input.Find("potato") != -1) {
					cout << CYAN_ << "You picked up the potato" << RESET_COLOUR << endl;
					hasPotato = true;
				}
			}
			else if (m_position.x == BEDROOM.x && m_position.y == BEDROOM.y && !hasMeat) {
				if (input.Find("meat") != -1) {
					cout << CYAN_ << "You picked up the meat" << RESET_COLOUR << endl;
					hasMeat = true;
				}
			}
			else if (m_position.x == STUDY.x && m_position.y == STUDY.y && !hasKey) {
				if (input.Find("key") != -1) {
					cout << CYAN_ << "You picked up the key" << RESET_COLOUR << endl;
					hasKey = true;
				}
			}
			else if (m_position.x == KITCHEN.x && m_position.y == KITCHEN.y && !hasSoup && soup->CheckFinished()) {
				if (input.Find("soup") != -1) {
					cout << CYAN_ << "You picked up the soup" << RESET_COLOUR << endl;
					hasSoup = true;
				}
			}
			else { cout << "I don't think you can pick that up" << endl; }
			break;
		case LOOKAT:
			if (hasTorch && input.Find("torch") != -1 || !hasTorch && input.Find("torch") != -1 && m_position.x == HALLWAY_SOUTH.x && m_position.y == HALLWAY_SOUTH.y ||
				!hasTorch && input.Find("sconce") != -1 && m_position.x == HALLWAY_SOUTH.x && m_position.y == HALLWAY_SOUTH.y) {
				torch->Description(hasTorch);
			}
			else if (hasPotato && input.Find("potato") != -1) {
				potato->Description(hasPotato);
			}
			else if (!hasPotato && input.Find("sack") != -1 && m_position.x == PANTRY.x && m_position.y == PANTRY.y) {
				cout << CYAN_ << "You go through one of the sacks and find a potato!" << RESET_COLOUR << endl;
			}
			else if (hasMeat && input.Find("meat") != -1 || !hasMeat && input.Find("meat") != -1 && m_position.x == BEDROOM.x && m_position.y == BEDROOM.y) {
				meat->Description();
			}
			else if (hasSoup && input.Find("soup") != -1) {
				soup->Description();
			}
			else if (!hasKey && input.Find("book") != -1 && m_position.x == STUDY.x && m_position.y == STUDY.y 
				|| !hasKey && input.Find("desk") != -1 && m_position.x == STUDY.x && m_position.y == STUDY.y) {
				cout << CYAN_ << "You move the book on the desk and find a key sitting underneath" << RESET_COLOUR << endl;
			}
			else if (hasKey && input.Find("key") != -1 || !hasKey && m_position.x == STUDY.x && m_position.y == STUDY.y) {
				cout << "A slightly rusty key" << endl;
			}
			else {
				input.Replace("lookat ", ""); 
				input.Replace("look at ", "");
				cout << "There is no " << input.str << " here" << endl;
			}
			break;
		case TALK:
			if (!dialogue1) {
				cout << CYAN_ << "You ask about where you are and how to leave" << endl;
				cout << INDENT << BLUE << "YOU'RE IN MY 'OUSE, I WAS TOLD TO KEEP MY EYE ON YOU" << RESET_COLOUR << endl;
				dialogue1 = true;
			}
			else if (!dialogue2) {
				cout << CYAN_ << "You ask if he could move out of the way" << endl;
				cout << INDENT << BLUE << "NUH UH, I DON' MOVE FOR NUFFIN'" << RESET_COLOUR << endl;
				cout << "The creatures stomach grumbles" << endl;
				cout << INDENT << BLUE << "WELL, NUFFIN BUT SOME GOOD OL' GRUB! BWAH HAH HAH" << RESET_COLOUR << endl;
				dialogue2 = true;
			}
			else {
				cout << CYAN_ << "You ask what kind of food he likes" << endl;
				cout << INDENT << BLUE << "I'S BEEN WANTIN' A NICE SOUP, BUT I'S A BAD COOK" << RESET_COLOUR << endl;
			}
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
			}if (hasKey) {
				cout << "Key" << endl;
			}if (!hasTorch && !hasPotato && !hasMeat && !hasSoup && !hasKey) {
				cout << "You have nothing in your inventory" << endl;
			}
			break;
		case SPELLBOOK:
			cout << "Spells" << endl;
			for (int i = 0; i < 3; i++) {
				cout << spells[i].str << endl;
			}
			break;
		case HINT:
			if (!hasPotato && !hasSoup) {
				cout << "Maybe you should use one of your spells to check out the crack in the south hallway" << endl;
			}
			else if (!hasKey) {
				cout << "Maybe you should check out the study a little more" << endl;
			}
			else if (!hasSoup) {
				cout << "Maybe you should try finishing whatever's in the cookpot in the Kitchen" << endl;
			}
			else if (hasSoup) {
				cout << "Give the monster guy his soup!" << endl;
			}
			break;
		case FIND_SPELL:
			if (SearchForSpell(input)) {
				cout << "That spell is in your spellbook" << endl;
			}
			else { cout << "That spell is not in your spellbook" << endl; }
			break;
		default:
			cout << "I don't think you can do that" << endl;
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

