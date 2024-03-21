#include "Room.h"
#include "GameDefines.h"
#include <iostream>

using namespace std;

Room::Room(Point2D position) : m_mapPosition{ position } {
	//if (position.x == START.x && position.y == START.y || position.x == HALLWAY_NORTH.x && position.y == HALLWAY_NORTH.y || position.x == HALLWAY_SOUTH.x && position.y == HALLWAY_SOUTH.y) {
	//	canMoveNorth = true;
	//	canMoveEast = true;
	//	canMoveWest = true;
	//	canMoveSouth = true;
	//}if (position.x == EXIT.x && position.y == EXIT.y) {
	//	canMoveSouth = true;
	//}if (position.x == POOL.x && position.y == POOL.y || position.x == KITCHEN.x && position.y == KITCHEN.y || position.x == PANTRY.x && position.y == PANTRY.y) {
	//	canMoveEast = true;
	//}if (position.x == OBSERVATORY.x && position.y == OBSERVATORY.y || position.x == STUDY.x && position.y == STUDY.y || position.x == BEDROOM.x && position.y == BEDROOM.y) {
	//	canMoveWest = true;
	//}if (position.x == GARDEN.x && position.y == GARDEN.y) {
	//	canMoveNorth = true;
	//}
}

void Room::Description(bool hasTorch, bool hasMeat, bool hasPotato, bool hasSoup) {
	if (m_mapPosition.x == KITCHEN.x && m_mapPosition.y == KITCHEN.y) {
		cout << "You see a dusty kitchen before you; the left wall seems to have fallen victim to a cave-in" << endl;
		cout<<"and a cookpot sits in an unlit fireplace at the far end" << endl;
	}
	if (m_mapPosition.x == HALLWAY_NORTH.x && m_mapPosition.y == HALLWAY_NORTH.y) {
		cout << "You are in a Hallway, there are doors to the north, west and east. The hallway continues to the south" << endl;
		if (!hasTorch) {
			cout << "Torch sconces line the walls at even intervals" << endl;
		}
	}
	if (m_mapPosition.x == STUDY.x && m_mapPosition.y == STUDY.y) {

	}
}
