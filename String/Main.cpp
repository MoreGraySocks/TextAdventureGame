#include <iostream>
#include "String.h"
#include "StringTest.h"
#include "Game.h"
#include "Player.h"

using namespace std;

int main() {

	//cout << "Hello World\n" << endl;
	//StringTest test;
	//test.TestStringClass();
	Game game;
	Player player;
	int command = game.GetCommand();

	player.ExecuteCommand(command, game.m_savedInput);

}