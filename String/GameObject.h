#pragma once
#include "Point2D.h"

class GameObject
{
	//the class that will parent: item, player, room
private:
	GameObject();
	~GameObject();

private:
	Point2D m_mapPosition;

};

