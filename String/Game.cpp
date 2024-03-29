#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

Game::Game() : m_gameOver{ false } {
	m_savedInput.str = "nobodywillever type thisinthe console";
}
Game::~Game() {}

void Game::StartUp() {
	InitialiseRooms();

	player.SetPosition(HALLWAY_NORTH);
	player.ExecuteCommand(HELP, m_savedInput, m_rooms);

	cout << RESET_COLOUR;
}

void Game::Update() {

	if (player.GetPosition().x == EXIT.x && player.GetPosition().y == EXIT.y) {
		m_gameOver = true;
		return;
	}

	m_rooms[player.GetPosition().x][player.GetPosition().y].Description(player.hasTorch, player.hasPotato, player.hasMeat, player.hasSoup, player.hasKey, m_rooms, player.exitUnlocked);

	if (player.soup->CheckFinished() && !player.hasSoup && !player.exitUnlocked) {
		cout << "The soup is ready!" << endl;
	}
	int command = GetCommand(); 

	if (command == QUIT) {
		m_gameOver = true;
		return;
	}

	player.ExecuteCommand(command, m_savedInput, m_rooms); 
}

void Game::InitialiseRooms() {
	for (int i2 = 0; i2 < MAP_HEIGHT; i2++) {
		for (int i = 0; i < MAP_WIDTH; i++) {
			m_rooms[i][i2].SetPosition(Point2D{ i,i2 }); 
			m_rooms[i][i2].canMoveNorth = false;
			m_rooms[i][i2].canMoveEast = false;
			m_rooms[i][i2].canMoveWest = false;
			m_rooms[i][i2].canMoveSouth = false;
			m_rooms[i][i2].cookpotLit = false;
			if (i == HALLWAY_NORTH.x && i2 == HALLWAY_NORTH.y) { 
				m_rooms[i][i2].canMoveNorth = true; 
				m_rooms[i][i2].canMoveEast = true; 
				m_rooms[i][i2].canMoveWest = true; 
				m_rooms[i][i2].canMoveSouth = true; 
			}if (i == EXIT.x && i2 == EXIT.y) { 
				m_rooms[i][i2].canMoveSouth = true; 
			}if (i == KITCHEN.x && i2 == KITCHEN.y || i == PANTRY.x && i2 == PANTRY.y) { 
				m_rooms[i][i2].canMoveEast = true; 
			}if (i == STUDY.x && i2 == STUDY.y || i == BEDROOM.x && i2 == BEDROOM.y) { 
				m_rooms[i][i2].canMoveWest = true; 
			}if (i == HALLWAY_SOUTH.x && i2 == HALLWAY_SOUTH.y) { 
				m_rooms[i][i2].canMoveNorth = true; 
				m_rooms[i][i2].canMoveEast = true; 
				m_rooms[i][i2].canMoveWest = true; 
			}
		}
	}
}

int Game::GetCommand() {
	String input;

	cout << CYAN << INDENT;
	getline(cin, input.str);
	SaveInput(input);
	cout << RESET_COLOUR;

	input.ToLower();

	if (input.Find("help") != -1) {
		return HELP;
	}
	if (input.Find("move") != -1) {
		if (input.Find("north") != -1) {
			return NORTH;
		}if (input.Find("east") != -1) {
			return EAST;
		}if (input.Find("west") != -1) {
			return WEST;
		}if (input.Find("south") != -1) {
			return SOUTH;
		}
	}
	if (input.Find("use") != -1) {
		if (input.Find("torch") != -1) {
			return TORCH;
		}if (input.Find("potato") != -1) {
			return POTATO;
		}if (input.Find("meat") != -1) {
			return MEAT;
		}if (input.Find("soup") != -1) {
			return SOUP;
		}if (input.Find("flame") != -1) {
			return FLAME;
		}if (input.Find("key") != -1) {
			return KEY;
		}
	}
	if (input.Find("pickup") != -1 || input.Find("pick up") != -1) {
		return PICKUP;
	}
	if (input.Find("lookat") != -1 || input.Find("look at") != -1) {
		return LOOKAT;
	}
	if (input.Find("talk") != -1) {
		return TALK;
	}
	if (input.Find("inventory") != -1) {
		return INVENTORY;
	}
	if (input.Find("spellbook") != -1 || input.Find("spell book") != -1) {
		return SPELLBOOK;
	}
	if (input.Find("hint") != -1) {
		return HINT;
	}
	if (input.Find("spell") != -1) {
		return FIND_SPELL;
	}
	if (input.Find("quit") != -1) {
		return QUIT;
	}

	return 0;
}