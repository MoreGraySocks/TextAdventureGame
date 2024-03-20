#pragma once
#include "GameObject.h"
#include "String.h"

class Player : public GameObject
{
public:
	Player();
	~Player() {}

	void ExecuteCommand(int command, String input);

	void Description();

	bool SearchForSpell(String input);

public:
	String spells[3];

	bool hasTorch;
	bool hasSoup;
	bool hasPotato;
	bool hasMeat;

};

