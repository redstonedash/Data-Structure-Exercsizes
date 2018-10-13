#pragma once
#include "raylib.h"
class Item {
	Image image;
	Texture2D texture;
public:
	char* Type = '\0';
	char SubType = '1';
	char Quality = 'a'; //quality is alphabetic
	Item();
	Item(char* name, char subType, char quality);
	void draw(int x, int y);
	bool operator==(Item i);
	bool operator!=(Item i);
};
class Inventory {
	
public:
	Item inventory[64];
	Inventory();
	Inventory operator+(Item item);
	Inventory operator-(Item item);
	Inventory operator+=(Item item);
	Inventory operator-=(Item item);
	void draw(int x, int y);
};