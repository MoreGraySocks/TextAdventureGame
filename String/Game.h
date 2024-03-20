#pragma once
#include "GameDefines.h"
#include "String.h"

class Game
{
public:
	Game();
	~Game();


	void Update();
	bool IsGameOver();

	int GetCommand();
private:

	void DrawMap();

	void SaveInput(String input) { m_savedInput = input; }

public:
	String m_savedInput;

private:
	bool m_gameOver;
};

