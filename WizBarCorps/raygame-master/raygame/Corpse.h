//Corpse.h
#pragma once
#include <iostream>
#include "raylib.h"
#include "Wizard.h"
#include "Barbarian.h"

class Corpse
{
public:
	Corpse();           // sets default values
	Corpse(Wizard w);
	Corpse(Barbarian b);
	std::string name;

	int gold;

	Vector2 position;

	void draw();        // call this in your draw loop to render the wizard
};