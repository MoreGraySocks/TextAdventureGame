#include "Room.h"
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

void Room::Description(bool hasTorch, bool hasPotato, bool hasMeat, bool hasSoup, bool hasKey, Room rooms[MAP_WIDTH][MAP_HEIGHT], bool exitUnlocked) {
	if (m_mapPosition.x == KITCHEN.x && m_mapPosition.y == KITCHEN.y) {
		cout << "You see a dusty kitchen before you; the left wall seems to have fallen victim to a cave-in" << endl;
		if (rooms[KITCHEN.x][KITCHEN.y].cookpotLit) {
			cout << "the warm light and the bubbing cookpot bring a little bit more life to the room" << endl;
		}
		else { cout << "A cookpot full of water sits in an unlit fireplace at the far end" << endl; }
		
	}
	if (m_mapPosition.x == HALLWAY_NORTH.x && m_mapPosition.y == HALLWAY_NORTH.y) {
		if (!exitUnlocked) {
			cout << "You are in a Hallway, guarded by a large, yeti-like creature sitting at the northern end" << endl;
			cout << "There are doors to the west and east and the hallway continues to the south" << endl;
		}
		else {
			cout << "The exit is right in front of you" << endl;
		}
	}
	if (m_mapPosition.x == STUDY.x && m_mapPosition.y == STUDY.y) {
		cout << "You're in a comfortably sized study, it smells like old books and dust" << endl;
		if (!hasKey) {
			cout << "There is a book sitting on a large desk at the far end of the room" << endl;
		}
	}
	if (m_mapPosition.x == HALLWAY_SOUTH.x && m_mapPosition.y == HALLWAY_SOUTH.y) {
		cout << "You are in a Hallway, there is a door to the east and a large yeti-shaped hole on the western wall. The hallway goes back to the north" << endl;
		if (!hasTorch) {
			cout << "There is a torch sconce against the southern wall" << endl;
		}
	}
	if (m_mapPosition.x == BEDROOM.x && m_mapPosition.y == BEDROOM.y) {
		cout << "You are in a surprisingly frigid bedroom. A large four-posted bed sits against the back wall, the centre of the it heavily indented" << endl;
		if (!hasMeat) {
			cout << "A hefty slab of mystery meat sits on a side table next to the bed.. a midnight snack, perhaps?" << endl;
		}
	}
	if (m_mapPosition.x == PANTRY.x && m_mapPosition.y == PANTRY.y) {
		cout << "You are in a wide walk-in pantry, which feels a little more claustrophobic due to the cave-in on the right side" << endl;
		if (!hasPotato) {
			cout << "There are a couple sacks piled up against the left wall" << endl;
		}
	}
}
