#include "Room.h"
#include "GameDefines.h"

using namespace std;

Room::Room(Point2D position) : m_mapPosition{ position } {
	canMoveNorth = false;
	canMoveEast = false;
	canMoveWest = false;
	canMoveSouth = false;
	if (position.x == KITCHEN.x && position.y == KITCHEN.y) {
		canMoveEast = true;
	}if (position.x == HALLWAY_NORTH.x && position.y == HALLWAY_NORTH.y) {
		canMoveNorth = true;
		canMoveEast = true;
		canMoveWest = true;
		canMoveSouth = true;
	}if (position.x == STUDY.x && position.y == STUDY.y) {
		canMoveWest = true;
	}
}

void Room::Description() {
	if (m_mapPosition.x == KITCHEN.x && m_mapPosition.y == KITCHEN.y) {

	}
	if (m_mapPosition.x == HALLWAY_NORTH.x && m_mapPosition.y == HALLWAY_NORTH.y) {

	}
	if (m_mapPosition.x == STUDY.x && m_mapPosition.y == STUDY.y) {

	}
}
