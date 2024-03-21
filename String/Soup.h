#pragma once
#include "Item.h"

class Soup : public Item
{
public:
	Soup() : m_addedPotato{ false }, m_addedMeat{ false }, m_isFinished{ false } {}
	~Soup() {}

	void AddPotato() { m_addedPotato = true; }
	void AddMeat() { m_addedMeat = true; }

	void Description();
	bool Use(Room rooms[MAP_WIDTH][MAP_HEIGHT], Point2D playerPos);

	bool CheckFinished();

public:
	bool m_addedPotato;
	bool m_addedMeat;

	bool m_isFinished;

};

