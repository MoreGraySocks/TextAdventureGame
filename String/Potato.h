#pragma once
#include "Item.h"

class Potato : public Item
{
	Potato();
	~Potato();

	void Description(bool hasPotato);
	void Use(Room rooms[MAP_WIDTH][MAP_HEIGHT], Point2D playerPos);

	void AddToPot();
};

