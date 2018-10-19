#include "Barbarian.h"

Barbarian::Barbarian()
{
	position = { (float)(rand() % 800 + 25),(float)(rand() % 650 + 25) };
}

void Barbarian::draw()
{
	DrawText("B",(int)position.x,(int)position.y,32,MAROON);
}
