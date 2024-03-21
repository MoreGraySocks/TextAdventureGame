#include <iostream>
#include "String.h"
#include "StringTest.h"
#include "Game.h"
#include "Player.h"

using namespace std;

int main() {

	
	Game game;

	game.StartUp();
	
	while (game.IsGameOver() == false) {
		game.Update();
	}

	//done
}