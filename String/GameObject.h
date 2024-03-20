#pragma once
#include "Point2D.h"
#include "GameDefines.h"
#include <iostream>

class GameObject
{
	//the class that will parent: item, player
public:
	GameObject();
	GameObject(Point2D position);
	~GameObject();

	Point2D GetPosition() { return m_position; }
	void SetPosition(const Point2D& position) { m_position = position; }

	virtual void Description() = 0;

protected:
	Point2D m_position;

};

