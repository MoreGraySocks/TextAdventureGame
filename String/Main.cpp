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

	game.StartUp();
	
	while (game.IsGameOver() == false) {
		game.Update(game.m_rooms);
	}
}