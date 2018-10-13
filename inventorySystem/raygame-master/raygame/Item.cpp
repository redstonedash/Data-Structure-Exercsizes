#include "InventoryManagment.h"
#define _CRT_SECURE_NO_WARNINGS
#include "raylib.h"
#include <iostream>
#include <string>
Item::Item() {


}
Item::Item(char* name, char subType, char quality)
{
	Type = name;
	SubType = subType;
	Quality = quality;
	std::string temp("resources/32x32/"); 
	temp.append(name);
	temp.append("_0");
	temp+=subType;
	temp+=quality;
	temp.append("\0");
	temp.append(".png");
	image = LoadImage(temp.c_str());
	ImageFormat(&image, UNCOMPRESSED_R8G8B8A8);
	texture = LoadTextureFromImage(image);
}

void Item::draw(int x, int y) { //if begin draw has not been called, your doing it wrong
	DrawTexture(texture, x, y,WHITE);
}

bool Item::operator==(Item item)
{
	return SubType == item.SubType && Type == item.Type && Quality == item.Quality;
}

bool Item::operator!=(Item item)
{
	return SubType == item.SubType|| Type == item.Type || Quality == item.Quality;
}
