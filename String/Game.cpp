#include "Game.h"
#include "String.h"
#include <iostream>
#include <string>

using namespace std;

Game::Game(){}
Game::~Game(){}

void Game::Update() {

}

bool Game::IsGameOver() {
	return m_gameOver;
}

void Game::DrawMap() {

}

int Game::GetCommand() {
	String* input =  new String();

	//cin.clear();
	//cin.ignore(cin.rdbuf()->in_avail());
	cout << CYAN;
	getline(cin, input->str);
	cout << RESET_COLOUR;

	input->ToLower();

	if (input->Find("help") != -1) {
		return HELP;
	}
	if (input->Find("move") != -1) {
		cout << "move received" << endl;
		if (input->Find("north") != -1) {
			cout << "You chose to move north" << endl;
			return NORTH;
		}if (input->Find("east") != -1) {
			cout << "You chose to move east" << endl;
			return EAST;
		}if (input->Find("west") != -1) {
			cout << "You chose to move west" << endl;
			return WEST;
		}if (input->Find("south") != -1) {
			cout << "You chose to move south" << endl;
			return SOUTH;
		}
	}
	if (input->Find("use") != -1) {
		return USE;
	}
	if (input->Find("pickup") != -1 || input->Find("pick up") != -1) {
		return PICKUP;
	}
	if (input->Find("lookat") != -1 || input->Find("look at") != -1) {
		return LOOKAT;
	}
	if (input->Find("talk") != -1) {
		return TALK;
	}
	if (input->Find("inventory") != -1) {
		return INVENTORY;
	}
	if (input->Find("spellbook") != -1 || input->Find("spell book") != -1) {
		return SPELLBOOK;
	}
	if (input->Find("h9") != -1) {
		return DROP;
	}
	if (input->Find("drop") != -1) {
		return DROP;
	}

	input = nullptr;
	delete input;

	return 0;
}