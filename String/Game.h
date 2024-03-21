#pragma once
#include "GameDefines.h"
#include "String.h"
#include "Room.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();

public:
	void StartUp();

	void Update(Room rooms[MAP_WIDTH][MAP_HEIGHT]);
	bool IsGameOver() { return m_gameOver; }

private:
	void InitialiseRooms();
	void DrawMap();

	int GetCommand();

	void SaveInput(String input) { m_savedInput = input; }

public:
	String m_savedInput;

	Room m_rooms[MAP_WIDTH][MAP_HEIGHT];

	Player player;

private:
	bool m_gameOver;
};

