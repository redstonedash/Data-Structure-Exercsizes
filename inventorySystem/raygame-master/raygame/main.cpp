#include "raylib.h"
#include "InventoryManagment.h"
#include <iostream>

int main()
{
	SetTargetFPS(120);
	InitWindow(800, 650, "inventory");
	Inventory player = Inventory();
	Inventory NPCs[] = { Inventory(), Inventory(), Inventory()};
	for (int i = 0; i < 64/3; i++)
	{
		NPCs[0] += Item((char*)"sword", '1', 'a');
	}
	for (int i = 0; i < 64/3; i++)
	{
		NPCs[1] += Item((char*)"potion", '1', 'a');
	}
	for (int i = 0; i < 64/3; i++)
	{
		NPCs[2] += Item((char*)"shield", '3', 'e');
	}
	int activeNpc = 0;
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("Player",0,0,32,BLACK);
		player.draw(0, 32);
		NPCs[activeNpc].draw(500, 32);
		DrawText("Jon", 0, 400, 32, BLACK);
		DrawText("Terry", 0, 432, 32, BLACK);
		DrawText("James", 0, 464, 32, BLACK);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			if (GetMousePosition().y > 400 && GetMousePosition().y < 432) {
				activeNpc = 0;
			}						 
			if (GetMousePosition().y > 432 && GetMousePosition().y < 464) {
				activeNpc = 1;
			}
			if (GetMousePosition().y > 464 && GetMousePosition().y < 498) {
				activeNpc = 2;
			}
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (GetMousePosition().x > (i * 32 + 500) && GetMousePosition().x < ((i + 1) * 32 + 500) && GetMousePosition().y > (j * 32 + 32) && GetMousePosition().y < ((j + 1) * 32 + 32)) {
						player += NPCs[activeNpc].inventory[i + j * 8];
						NPCs[activeNpc] -= NPCs[activeNpc].inventory[i + j * 8];
						break;
					}
				}
			}
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (GetMousePosition().x >(i * 32) && GetMousePosition().x < ((i + 1) * 32) && GetMousePosition().y >(j * 32 + 32) && GetMousePosition().y < ((j + 1) * 32 + 32)) {
						NPCs[activeNpc] += player.inventory[i + j * 8];
						player -= player.inventory[i + j * 8];
						break;
					}
				}
			}
		}
		DrawFPS(700, 15);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}