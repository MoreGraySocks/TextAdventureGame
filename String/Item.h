#pragma once
#include "GameObject.h"
#include "Room.h"

class Item : public GameObject
{
public:
	Item();
	Item(Point2D position);
	~Item();

	void Description() = 0;
	virtual void Use() = 0;
};

