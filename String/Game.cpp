#include "Game.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

Game::Game() : m_gameOver{ false } {
	m_savedInput.str = "nobodywillever type thisinthe console";
}
Game::~Game() {}

void Game::Update() {
	Player player; 

	while (IsGameOver() == false) { 
		int command = GetCommand(); 

		player.ExecuteCommand(command, m_savedInput); 

	}
}

void Game::InitialiseRooms() {
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int i2 = 0; i2 < MAP_HEIGHT; i++) {
			m_rooms[i][i2].SetPosition(Point2D{ i,i2 });
		}
	}
}

void Game::DrawMap() {

}

int Game::GetCommand() {
	String input;

	cout << CYAN;
	getline(cin, input.str);
	SaveInput(input);
	cout << RESET_COLOUR;

	input.ToLower();

	if (input.Find("help") != -1) {
		return HELP;
	}
	if (input.Find("spell") != -1) {
		return FIND_SPELL;
	}
	if (input.Find("move") != -1) {
		//cout << "move received" << endl;
		if (input.Find("north") != -1) {
			//cout << "You chose to move north" << endl;
			return NORTH;
		}if (input.Find("east") != -1) {
			//cout << "You chose to move east" << endl;
			return EAST;
		}if (input.Find("west") != -1) {
			//cout << "You chose to move west" << endl;
			return WEST;
		}if (input.Find("south") != -1) {
			//cout << "You chose to move south" << endl;
			return SOUTH;
		}
	}
	if (input.Find("use") != -1) {
		//return USE;
		if (input.Find("torch") != -1) {
			return TORCH;
		}if (input.Find("potato") != -1) {
			return POTATO;
		}if (input.Find("meat") != -1) {
			return MEAT;
		}if (input.Find("pot") != -1) {
			return POT;
		}if (input.Find("soup") != -1) {
			return SOUP;
		}if (input.Find("flame") != -1) {
			return FLAME;
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
	if (input.Find("drop") != -1) {
		return DROP;
	}

	return 0;
}