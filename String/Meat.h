#pragma once
#include "Item.h"
class Meat : public Item
{
public:
	Meat();
	~Meat();

	void Description();
	bool Use(Room rooms[MAP_WIDTH][MAP_HEIGHT], Point2D playerPos);
};

