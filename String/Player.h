#pragma once
#include "GameObject.h"
#include "String.h"
#include "Room.h"
#include "Torch.h"
#include "Soup.h"
#include "Potato.h"
#include "Meat.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void ExecuteCommand(int command, String input, Room rooms[MAP_WIDTH][MAP_HEIGHT]);

	void Description();

	bool SearchForSpell(String input);

public:
	String spells[3];

	bool hasTorch;
	bool hasSoup;
	bool hasPotato;
	bool hasMeat;
	bool hasKey;
	bool bedroomUnlocked;
	bool exitUnlocked;

	bool dialogue1;
	bool dialogue2;

	Torch* torch;
	Soup* soup;
	Potato* potato;
	Meat* meat;

};

