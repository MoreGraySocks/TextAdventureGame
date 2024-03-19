#pragma once
#include "GameObject.h"

class Item : public GameObject
{
public:
	Item();
	Item(Point2D position);
	~Item();
};

