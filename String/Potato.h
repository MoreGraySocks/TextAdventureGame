#pragma once
#include "Item.h"

class Potato : public Item
{
public:
	Potato();
	~Potato();

	void Description(bool hasPotato);
	bool Use(Room rooms[MAP_WIDTH][MAP_HEIGHT], Point2D playerPos);

};

