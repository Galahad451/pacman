#include "raylib.h"
#include "colores.h"
#include <iostream>

#define screenWidth 945
#define screenHeight 945

Rectangle moveMent(int number, Rectangle position, int vel){
	Rectangle rec = position;
	switch (number){
		case 0:
		rec.x = rec.x;
		break;
		case 1:
		rec.x = rec.x + 1*vel;
		break;
		case 2:
		rec.y = rec.y + 1*vel;
		break;
		case 3:
		rec.x = rec.x - 1*vel;
		break;
		case 4:
		rec.y = rec.y - 1*vel;
		break;
		default:
		rec.x = rec.x;
		rec.y = rec.y;
		break;
	}
	return rec;
}

int main(){
	Colores *color = new Colores();

	InitWindow(screenWidth, screenHeight, "Pac Man - Juan Pablo De Alba");
	SetTargetFPS(60);

	float size = 0.5;


	Texture2D pacman = LoadTexture("workspace/pacman/img/sheet.png");
	int frameWidth = pacman.width/6;
	int frameHeight = pacman.height;
	Rectangle sourceRec = { 0, 0, (float)frameWidth, (float)frameHeight};
	Rectangle destRec = {0, 0, (float)frameWidth*size, (float)frameHeight*size};

	Vector2 origin = {(float)frameWidth*(size/2), (float)frameHeight*(size/2)};


	int currentFrame = 0;
	int framesCounter = 0;
	int frameSpeed = 12;
	int rotation = 0;
	int move = 0;
	int velocity = 1;

	while(!WindowShouldClose()){
		
		destRec = moveMent(move, destRec, velocity);

		framesCounter++;

		if(framesCounter >= 60/frameSpeed)
		{
			framesCounter = 0;
			currentFrame++;
			if(currentFrame > 5){currentFrame = 0;}
			sourceRec.x = (float)currentFrame*(float)frameWidth;
		}

		if(IsKeyPressed(KEY_RIGHT))
		{
			move = 1;
			rotation = 90;
		}
		if(IsKeyPressed(KEY_DOWN))
		{
			move = 2;
			rotation = 180;
		}
		if(IsKeyPressed(KEY_LEFT))
		{
			move = 3;
			rotation = 270;
		}
		if(IsKeyPressed(KEY_UP))
		{
			move = 4;
			rotation = 0;
		}
		if(IsKeyPressed(KEY_U))
		{
			velocity++;
			if (velocity >= 1000)
			{
				velocity = 1000;
			}
		}
		if(IsKeyPressed(KEY_D))
		{
			velocity--;
			if (velocity <= 0)
			{
				velocity = 0;
			}
		}

		// if(framesCounter >= 60/frameSpeed){
		// 	currentFrame++;
		// 	if(framesCounter > 4){framesCounter = 0;}
		// 	frameRec.x = (float)currentFrame*(float)pacman.width/6;
		// }

		BeginDrawing();
		ClearBackground(color->GetColor(0,0,0,255));
		DrawTexturePro(pacman, sourceRec, destRec, origin, rotation, color->GetColor(255,255,255,255));
		EndDrawing();
	}
	UnloadTexture(pacman);
	CloseWindow();
	return 0;
}