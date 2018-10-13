#include "raylib.h"
#include <iostream>
#include <string>
class Potion {
public:
	char* Name;
	float HPModifier = 1.0f;
	float Quality;
	float UseByDate;
	Vector2 position;
	bool active = true;
};
class Hero{
public:
	char* Name;
	char* Special;
	float age = 0;
	float hitPoints = 1;
	float wealth = 0;
	Vector2 position = {0.0f,0.0f};
	Hero operator+=(Potion potion) {
		this->hitPoints += potion.HPModifier;
		return *this;
	}
};
int screenWidth = 800;
int screenHeight = 450;
float distance(Vector2 a, Vector2 b) {
	return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}
int main()
{
	InitWindow(screenWidth, screenHeight, "OMAN: im not very good at computer plz help");
	Image image[5] = { LoadImage("resources/ouch1.png"),LoadImage("resources/ouch2.png"),LoadImage("resources/ouch3.png"),LoadImage("resources/ouch4.png"),LoadImage("resources/ouch5.png") };
	Texture textureArr[5];
	for (int i = 0; i < 5; i++) {
		ImageFormat(&image[i], UNCOMPRESSED_R8G8B8A8);
		textureArr[i] = LoadTextureFromImage(image[i]);
	}
	SetTargetFPS(120);
	Hero doomGuy = Hero();
	Potion potion;
	potion.position = { (float)screenWidth / 2, (float)screenHeight / 2 };
	while (!WindowShouldClose()){
		doomGuy.hitPoints -= GetFrameTime() / 10;
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText(std::to_string(doomGuy.hitPoints).c_str(),0,0,100,BLACK);

		int i = 0;

		if (doomGuy.hitPoints > 1) {
			doomGuy.hitPoints = 1;
		}
		if (doomGuy.hitPoints <= 0) {
			return 0;
		}
		if (IsKeyDown(KEY_W)) {
			doomGuy.position = { doomGuy.position.x, doomGuy.position.y - (float)GetFrameTime() * 100 };
		}
		if (IsKeyDown(KEY_A)) {
			doomGuy.position = { doomGuy.position.x - (float)GetFrameTime() * 100, doomGuy.position.y };
		}
		if (IsKeyDown(KEY_S)) {
			doomGuy.position = { doomGuy.position.x, doomGuy.position.y + (float)GetFrameTime() * 100 };
		}
		if (IsKeyDown(KEY_D)) {
			doomGuy.position = { doomGuy.position.x + (float)GetFrameTime() * 100, doomGuy.position.y };
		}
		if (potion.active == true) {
			DrawCircle(potion.position.x, potion.position.y, 50, BLUE);
			if (distance(doomGuy.position,potion.position)<=50) {
				doomGuy += potion;
				potion.active = false;
			}
		}
		DrawTexture(textureArr[(int)(5*(1-doomGuy.hitPoints))], doomGuy.position.x, doomGuy.position.y, WHITE);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}