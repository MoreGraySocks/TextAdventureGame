#pragma once
#include "Item.h"

class Torch
{
public:
	Torch() : m_isLit{ false } {}
	~Torch() {}

	void Description(bool hasTorch);
	void Use(Room rooms[MAP_WIDTH][MAP_HEIGHT], Point2D playerPos);

	bool CheckLit() { return m_isLit; }
	void LightTorch() { m_isLit = true; }

public:
	bool m_isLit;
};

