#pragma once
#include "GameDefines.h"

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


	void Save();
	bool Load();

private:
	
	bool m_gameOver;
};

