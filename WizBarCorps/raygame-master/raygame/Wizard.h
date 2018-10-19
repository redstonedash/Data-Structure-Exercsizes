//Wizard.h
#pragma once
#include <iostream>
#include "raylib.h"

class Wizard
{
public:
	Wizard();           // sets default values
	std::string name;
	int mana = 50;

	int gold;

	Vector2 position;

	void draw();        // call this in your draw loop to render the wizard
};