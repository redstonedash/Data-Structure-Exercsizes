#include "Corpse.h"

Corpse::Corpse()
{
}

Corpse::Corpse(Wizard w)
{
	gold = w.gold;
	position = w.position;
}

Corpse::Corpse(Barbarian b)
{
	gold = b.gold;
	position = b.position;
}

void Corpse::draw()
{
	DrawText("C", (int)position.x, (int)position.y, 32, DARKBROWN);
}
