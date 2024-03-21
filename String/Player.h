#pragma once
#include "GameObject.h"
#include "String.h"
#include "Room.h"
#include "Torch.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void ExecuteCommand(int command, String input, Room rooms[MAP_WIDTH][MAP_HEIGHT]);

	void Description();

	void AddTorch() { hasTorch = true; }
	void AddPotato() { hasPotato = true; }
	void AddMeat() { hasMeat = true; }

	bool SearchForSpell(String input);

public:
	String spells[3];

	bool hasTorch;
	bool hasSoup;
	bool hasPotato;
	bool hasMeat;

	Torch* torch;

};

