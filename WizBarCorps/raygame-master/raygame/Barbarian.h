//Barbarian.h
#pragma once
#include <iostream>
#include "raylib.h"
class Barbarian
{
public:
	Barbarian();           // sets default values

	std::string name;
	int strength = 50;

	int gold;

	Vector2 position;

	void draw();        // call this in your draw loop to render the wizard
};