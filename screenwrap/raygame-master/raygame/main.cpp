#include "raylib.h"
#include <iostream>
#include <cmath>
#include <string>

class pickup {
public:
	float x = 0;
	float y = 0;
	pickup() {
		x = rand() % 800;
		y = rand() % 650;
	}
	void rerand() {
		x = rand() % 800;
		y = rand() % 650;
	}
	void draw() {
		DrawCircle(x,y,10,BLUE);
	}
};

int main()
{
	pickup pickups[10];
	SetTargetFPS(120);
	float x = 0;
	float y = 0;
	float timer = 2.0f;
	InitWindow(800, 650, "screenwrap");
	while (!(WindowShouldClose() || timer <=0))
	{
		for (int i = 0; i < 10; i++) {
			pickups[i].draw();
			if (sqrt(pow((x - pickups[i].x), 2) + pow((y - pickups[i].y), 2))<60) {
				timer += 0.2f;
				pickups[i].rerand();
			}
		}
		
		DrawText(std::to_string(timer).c_str(), 0, 0, 64, {255,0,0,127});
		timer -= GetFrameTime();
		if (IsKeyDown(KEY_UP)) {
			y -= GetFrameTime() * 1000;
		}
		if (IsKeyDown(KEY_LEFT)) {
			x -= GetFrameTime() * 1000;
		}
		if (IsKeyDown(KEY_DOWN)) {
			y += GetFrameTime() * 1000;
		}
		if (IsKeyDown(KEY_RIGHT)) {
			x += GetFrameTime() * 1000;
		}
		if (x < -50) {
			x += 900;
		}
		if (y < -50) {
			y += 750;
		}
		if (x > 850) {
			x -= 900;
		}
		if (y > 700) {
			y -= 750;
		}
		DrawCircle(x,y,50,BLACK);
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawFPS(700, 15);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}