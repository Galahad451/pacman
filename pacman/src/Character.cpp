#include "Character.h"
#include <iostream>

using namespace std;

Character::Character(){
	rotation = 0;
	framesCounter = 0;
	currentFrame = 0;
	frameSpeed = 12;
	willMove = false;
	movimientoAnterior = 0;
	direction = 1;
	change = 1;
	velocity = 3;
	notMoving = 0;
	death = false;
	danger = false;
}

Character::~Character(){
}

void Character::createChar(const char *source, int frames, float size){
	name = LoadTexture(source);
	frameWidth = name.width/frames;
	frameHeight = name.height;
	sourceRec.x = 0;
	sourceRec.y = 0;
	sourceRec.width = (float)frameWidth;
	sourceRec.height = (float)frameHeight;
	destRec.x = 0;
	destRec.y = 0;
	destRec.width = (float)frameWidth*size;
	destRec.height = (float)frameHeight*size;
	origin.x = (float)frameWidth*(size/2);
	origin.y = (float)frameHeight*(size/2);
}

void Character::setDanger(int number){
	if (number == 1)
	{
		framesCounter = 120;
		currentFrame = 10;
		firstFrame = 10;
		lastFrame = 11;
		velocity = 1;
		if (danger == false)
		{
			danger = true;
		}else
		{
			death = true;
		}
	}
	if (number == 0)
	{
		danger = false;
		death = false;
		velocity = 3;
	}
}

void Character::Update(int number){
	framesCounter++;

	if(framesCounter >= 60/frameSpeed && willMove == true)
	{
		framesCounter = 0;
		currentFrame++;
		if(currentFrame > lastFrame){currentFrame = firstFrame;}
		sourceRec.x = (float)currentFrame*(float)frameWidth;
	}
	if (number == 0 && death == false)
	{
		firstFrame = 0;
		lastFrame = 5;
	}
	if (number == 1)
	{
		if (danger == false)
		{
			if (direction == 1)
			{
				firstFrame = 2;
				lastFrame = 3;
			}
			else if (direction == 2)
			{
				firstFrame = 4;
				lastFrame = 5;
			}
			else if (direction == 3)
			{
				firstFrame = 6;
				lastFrame = 7;
			}
			else if (direction == 4)
			{
				firstFrame = 0;
				lastFrame = 1;
			}
		}
		else
		{
			if (death == false)
			{
				firstFrame = 10;
				lastFrame = 11;
			}
			else
			{
				firstFrame = 8;
				lastFrame = 9;
			}
		}
	}
}

void Character::Render(){
	DrawTexturePro(name, sourceRec, destRec, origin, rotation, white);
}

bool Character::setBack(int x, int y){
	if ((destRec.x < x - 3 || destRec.x > x + 3) || (destRec.y < y - 3 || destRec.y > y + 3))
	{
		if (destRec.x <= x)
		{
			destRec.x+=2;
		}
		else 
		{
			destRec.x-=2;
		}
		if (destRec.y <= y)
		{
			destRec.y+=2;
		}
		else
		{
			destRec.y-=2;
		}
		return false;
	}
	return true;
	
}


