#pragma once
#include "Item.h"

class Torch : public Item
{
public:
	Torch() : m_isLit{ false } {}
	~Torch() {}

	void Description(bool hasTorch);
	bool Use(Room rooms[MAP_WIDTH][MAP_HEIGHT], Point2D playerPos);

	bool CheckLit() { return m_isLit; }
	void LightTorch() { m_isLit = true; }

public:
	bool m_isLit;
};

