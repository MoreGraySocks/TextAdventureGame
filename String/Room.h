#pragma once
#include "Point2D.h"
#include "GameDefines.h"

class Room
{
public:
	Room() : m_mapPosition{ 0,0 }, canMoveNorth{ false }, canMoveEast{ false }, canMoveWest{ false }, canMoveSouth{ false }, cookpotLit{ false } {}
	Room(Point2D position);
	~Room() {}

	void SetPosition(Point2D position) { m_mapPosition = position; }
	Point2D GetPosition() { return m_mapPosition; }

	void Description(bool hasTorch, bool hasPotato, bool hasMeat, bool hasSoup, bool hasKey, Room rooms[MAP_WIDTH][MAP_HEIGHT], bool exitUnlocked);

public:
	Point2D m_mapPosition;

	bool canMoveNorth;
	bool canMoveEast;
	bool canMoveWest;
	bool canMoveSouth;

	bool cookpotLit;

	/* Finished Map *after nerf
	                 ___________
                     |   end   |
	                 |         |
	         ------------000-----------
		 	 |         |  h  |        |
			 | kitchen I  a  I  study |
			 |  	   |  l  |		  |
			 ----------|  l  |---------
			      |    |  w  |  bed   |
			pantry|	   I  a  I	room  |
				  |    |  y  |		  |
	              ---------------------
	
	*/

};

