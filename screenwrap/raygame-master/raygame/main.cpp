#include "raylib.h"
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

float playerX = 0;
float playerY = 0;
bool powerUp = true;
float powerUpX = rand() % 800;
float powerUpY = rand() % 650;
float powerUpTimer = 0;
int score = 0;


float distance(float x, float y, float x1, float y1) {
	return sqrt(pow((x - x1), 2) + pow((y - y1), 2));
}

class pickup{
public:
	bool enemy = false;
	float x = 0;
	float y = 0;
	float velX = 0;
	float velY = 0;
	pickup(bool side) {
		enemy = side;
		rerand();
	}
	pickup() {
		rerand();
	}
	void rerand() {
		x = rand() % 800;
		y = rand() % 650;
		velX = (rand() % 160)-80;
		velY = (rand() % 130) - 65;
	}
	void draw() {
		x += velX * GetFrameTime();
		y += velY * GetFrameTime();
		if (x < -10) {
			x += 820;
		}
		if (y < -10) {
			y += 670;
		}
		if (x > 810) {
			x -= 820;
		}
		if (y > 610) {
			y -= 670;
		}
		if (enemy) {
			velX = (x - playerX) / distance(x, y, playerX, playerY) * -50;
			velY = (y - playerY) / distance(x, y, playerX, playerY) * -50;
			DrawCircle(x, y, 10, RED);
		}
		else {
			DrawCircle(x, y, 10, BLUE);
		}
		
	}
};

int main(){
	
	pickup pickups[10];
	pickup enemy = pickup(true);
	SetTargetFPS(120);
	float timer = 5.0f;
	InitWindow(800, 650, "screenwrap");
	while (!(WindowShouldClose() || timer <=0))
	{

		for (int i = 0; i < 10; i++) {
			pickups[i].draw();
			if (sqrt(pow((playerX - pickups[i].x), 2) + pow((playerY - pickups[i].y), 2))<60) {
				timer += 0.2f;
				pickups[i].rerand();
				score++;
			}
		}
		if(distance(enemy.x, enemy.y, playerX, playerY)<60){
			timer -= 1;
			enemy.rerand();
		}
		enemy.draw();
		DrawText(std::to_string(timer).c_str(), 0, 0, 64, {255,0,0,127});
		timer -= GetFrameTime();
		
		if (powerUpTimer > 0) {
			powerUpTimer -= GetFrameTime();
		} else {
			powerUpTimer = 0;
		}

		if (IsKeyDown(KEY_W)) {
			playerY -= GetFrameTime() * 1000 * (powerUpTimer + 1);
		}
		if (IsKeyDown(KEY_A)) {
			playerX -= GetFrameTime() * 1000 * (powerUpTimer + 1);
		}
		if (IsKeyDown(KEY_S)) {
			playerY += GetFrameTime() * 1000 * (powerUpTimer + 1);
		}
		if (IsKeyDown(KEY_D)) {
			playerX += GetFrameTime() * 1000 * (powerUpTimer + 1);
		}

		if (playerX < -50) {
			playerX += 900;
		}
		if (playerY < -50) {
			playerY += 750;
		}
		if (playerX > 850) {
			playerX -= 900;
		}
		if (playerY > 700) {
			playerY -= 750;
		}

		DrawCircle(playerX,playerY,50,BLACK);//player
		if (powerUp) {
			DrawCircle(powerUpX, powerUpY, 20, GREEN);//powerUp
			if (distance(powerUpX, powerUpY, playerX, playerY) <= 70) {
				powerUp = false;
				powerUpTimer = 2;
			}
		}
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawFPS(700, 15);
		EndDrawing();
	}
	std::ifstream readFile;
	std::string line;
	readFile.open("score.txt");
	std::cout << readFile.fail();
	getline(readFile, line);
	readFile.close();
	int tempScore = 0;
	if ((line.find_first_not_of("0123456789") == std::string::npos)) {
		tempScore = std::stoi(line);
	}
	if (tempScore < score) {
		std::ofstream file;
		file.open("score.txt", std::ios::out | std::ios::trunc);
		file << std::to_string(score).c_str();
		file.close();
	}
	for (float i = 0; i < 2; i+=GetFrameTime()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("HIGHSCORE", 400, 200, 64, BLACK);
		if (tempScore > score) {
			
			DrawText(std::to_string(tempScore).c_str(), 400, 300, 64, BLACK);
			DrawText("YOURSCORE", 400, 400, 64, BLACK);
		}
		DrawText(std::to_string(score).c_str(), 400, 500, 64, BLACK);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}