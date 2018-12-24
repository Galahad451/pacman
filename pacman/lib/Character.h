#pragma once
#include "colores.h"

#include "raylib.h"

class Character{
public:
	Character();
	~Character();

	Texture2D name;
	int frameWidth;
	int frameHeight;
	int rotation;
	int framesCounter;
	int currentFrame;
	int frameSpeed;
	int direction;
	int change;
	int velocity;
	bool willMove;
	int notMoving;
	int movimientoAnterior;
	bool death;
	bool danger;

	int firstFrame;
	int lastFrame;

	Rectangle sourceRec;
	Rectangle destRec;
	Vector2 origin;

	void createChar(const char *source, int frames, float size);
	void setDanger(int number);
	void Render();
	bool setBack(int x, int y);
	void Update(int number);
};