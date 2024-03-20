#pragma once
#include "Item.h"

class Torch
{
public:
	Torch() : m_isLit{ false } {}
	~Torch() {}

	void Description();
	void Use();

	bool CheckLit() { return m_isLit; }
	void LightTorch() { m_isLit = true; }

public:
	bool m_isLit;
};

