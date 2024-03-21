#pragma once
#include "GameObject.h"
#include "Room.h"

class Item : public GameObject
{
public:
	Item();
	Item(Point2D position);
	~Item();

	void Description();
	virtual bool Use(Room rooms[MAP_WIDTH][MAP_HEIGHT], Point2D playerPos) = 0;
};

