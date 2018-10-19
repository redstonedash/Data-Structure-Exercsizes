#include "raylib.h"
#include "Wizard.h"
#include "Barbarian.h"

int main()
{
	float playerX = 100.0f;
	float playerY = 100.0f;
	const int numWiz = 2;
	const int numBar = 2;
	SetTargetFPS(120);
	InitWindow(900,700, "WisBarbCorpse");
	Wizard wizArr[numWiz];
	Barbarian barArr[numBar];

	while (!WindowShouldClose())
	{
		if(IsKeyDown(KEY_W)) {
			playerY -= GetFrameTime() * 20;
		}
		if (IsKeyDown(KEY_A)) {
			playerX -= GetFrameTime() * 20;
		}
		if (IsKeyDown(KEY_S)) {
			playerY += GetFrameTime() * 20;
		}
		if (IsKeyDown(KEY_D)) {
			playerX += GetFrameTime() * 20;
		}
		BeginDrawing();
		ClearBackground(RAYWHITE);
		for (int i = 0; i < numWiz; i++) {
			wizArr[i].draw();
		}
		for (int i = 0; i < numBar; i++) {
			barArr[i].draw();
		}
		DrawFPS(700, 15);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}