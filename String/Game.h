#pragma once
class Game
{
public:
	Game();
	~Game();


	void Update();
	bool IsGameOver();

private:

	void DrawMap();

	int GetCommand();

	void Save();
	bool Load();

private:
	
	bool m_gameOver;
};

