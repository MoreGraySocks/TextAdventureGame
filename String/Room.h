#pragma once
#include "Point2D.h"

class Room
{
public:
	Room() : m_mapPosition{ 0,0 } {}
	Room(Point2D position) : m_mapPosition{ position } {}
	~Room() {}

	void SetPosition(Point2D position) { m_mapPosition = position; }
	Point2D GetPosition() { return m_mapPosition; }

	void Description();

public:
	Point2D m_mapPosition;

	/* Finished Map
	
	                _____________  
	                |           |                                                  
	                |    end    |
                  -------ooo-------	 __________ 
	   -----------|               | /          \
	  |           |               |/            \
	  |   pool    I     start     I observatory  |
	  |           I               I              |
	  |           |               |\            /
	   -----------|               | \          /
	         ----------------------------------
		 	 |         |  h  |        |
			 | kitchen I  a  I  study |
			 |  	   |  l  |		  |
			 |		   |  l  |---------
			 ----------|  w  |  bed   |
			pantry|	   I  a  I	room  |
				  |    |  y  |		  |
	          -----------|-|-----------
			  |O                     O|
			  |                       |
			  |        garden         |
			  |                       |
			  |O                     O|
			  -------------------------
	
	*/

};

