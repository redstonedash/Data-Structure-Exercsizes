#include "Wizard.h"

Wizard::Wizard()
{
	position = {(float)(rand()%800 + 25),(float)(rand() % 650 + 25)};
}

void Wizard::draw()
{
	DrawText("W", (int)position.x, (int)position.y, 32, SKYBLUE);
}
