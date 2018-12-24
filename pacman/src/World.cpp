#include "World.h"
#include <iostream>
#include "Variables.h"

using namespace std;


World::World(){
	gameStage = 0;
	powerDotActivated = false;
	powerDotTimer = 0;
	activatedFlag = false;
	score = 0;
	lives = 3;
	int outOfBoundsArray[21][21] = {
	{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
	{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
	{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
	{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
	{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
	{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
	{1,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	1},
	{1,	1,	1,	1,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	1,	1,	1,	1},
	{0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0},
	{1,	1,	1,	1,	1,	0,	1,	1,	0,	1,	1,	1,	0,	1,	1,	0,	1,	1,	1,	1,	1},
	{0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0},
	{1,	1,	1,	1,	0,	0,	0,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	1,	1,	1,	1},
	{1,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	1},
	{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
	{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
	{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
	{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
	{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
	{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
	{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1},
	{1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1}};
	int arr[21][21] = {
	 {0, 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 0},
	 {0, 1,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 1,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 1,	 0},
	 {0, 1,	 0,	 1,	 1,	 0,	 1,	 1,	 1,	 0,	 1,	 0,	 1,	 1,	 1,	 0,	 1,	 1,	 0,	 1,	 0},
	 {0, 1,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 1,	 0},
	 {0, 1,	 0,	 1,	 1,	 0,	 1,	 0,	 1,	 1,	 1,	 1,	 1,	 0,	 1,	 0,	 1,	 1,	 0,	 1,	 0},
	 {0, 1,	 0,	 0,	 0,	 0,	 1,	 0,	 0,	 0,	 1,	 0,	 0,	 0,	 1,	 0,	 0,	 0,	 0,	 1,	 0},
	 {0, 1,	 1,	 1,	 1,	 0,	 1,	 1,	 1,	 0,	 1,	 0,	 1,	 1,	 1,	 0,	 1,	 1,	 1,	 1,	 0},
	 {0, 0,	 0,	 0,	 1,	 0,	 1,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 1,	 0,	 1,	 0,	 0,	 0,	 0},
	 {1, 1,	 1,	 1,	 1,	 0,	 1,	 0,	 1,	 1,	 1,	 1,	 1,	 0,	 1,	 0,	 1,	 1,	 1,	 1,	 1},
	 {0, 0,	 0,	 0,	 0,	 0,	 0,	 0,	 1,	 0,	 0,	 0,	 1,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0},
	 {1, 1,	 1,	 1,	 1,	 0,	 1,	 0,	 1,	 1,	 1,	 1,	 1,	 0,	 1,	 0,	 1,	 1,	 1,	 1,	 1},
	 {0, 0,	 0,	 0,	 1,	 0,	 1,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 1,	 0,	 1,	 0,	 0,	 0,	 0},
	 {0, 1,	 1,	 1,	 1,	 0,	 1,	 0,	 1,	 1,	 1,	 1,	 1,	 0,	 1,	 0,	 1,	 1,	 1,	 1,	 0},
	 {0, 1,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 1,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 1,	 0},
	 {0, 1,	 0,	 1,	 1,	 0,	 1,	 1,	 1,	 0,	 1,	 0,	 1,	 1,	 1,	 0,	 1,	 1,	 0,	 1,	 0},
	 {0, 1,	 0,	 0,	 1,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 1,	 0,	 0,	 1,	 0},
	 {0, 1,	 1,	 0,	 1,	 0,	 1,	 0,	 1,	 1,	 1,	 1,	 1,	 0,	 1,	 0,	 1,	 0,	 1,	 1,	 0},
	 {0, 1,	 0,	 0,	 0,	 0,	 1,	 0,	 0,	 0,	 1,	 0,	 0,	 0,	 1,	 0,	 0,	 0,	 0,	 1,	 0},
	 {0, 1,	 0,	 1,	 1,	 1,	 1,	 1,	 1,	 0,	 1,	 0,	 1,	 1,	 1,	 1,	 1,	 1,	 0,	 1,	 0},
	 {0, 1,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 0,	 1,	 0},
	 {0, 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 0}};

	 //POWER DOTS
	 cell[2][2].powerDot = true;
	 cell[2][18].powerDot = true;
	 cell[15][2].powerDot = true;
	 cell[15][18].powerDot = true;

	for(int i = 0 ; i < 21 ; i++)
	{
		for(int j = 0 ; j < 21 ; j++)
		{
			cell[i][j].x = 45 + 45*j;
			cell[i][j].y = 45 + 45*i;
			cell[i][j].wall = arr[i][j];
			cell[i][j].outOfBounds = outOfBoundsArray[i][j];
			if (cell[i][j].wall == false && cell[i][j].outOfBounds == false && cell[i][j].powerDot == false)
			{
				cell[i][j].dot = true;
			}
		}
	}

	solution = false;
	currentFrame = 0;
}	
World::~World(){}

void World::createCharacters(){
	pacman.createChar("workspace/pacman/img/pacman.png", 6, 0.35);
	pacman.destRec.x = 45*10 + pacman.frameWidth/6 + 1;
	pacman.destRec.y = 45*15 + pacman.frameWidth/6 + 1;
	pacman.firstFrame = 0;
	pacman.lastFrame = 5;

	blinky.createChar("workspace/pacman/img/blinky.png", 12, 0.35);
	blinky.destRec.x = 45*10 + blinky.frameWidth/8+5;
	blinky.destRec.y = 45*6 + blinky.frameHeight/2;
	blinky.willMove = false;
	blinky.frameSpeed = 5;
	blinky.firstFrame = 2;
	blinky.lastFrame = 3;

	clyde.createChar("workspace/pacman/img/clyde.png", 12, 0.35);
	clyde.destRec.x = 45*9 + clyde.frameWidth/8+5;
	clyde.destRec.y = 515;
	clyde.willMove = true;
	clyde.frameSpeed = 5;
	clyde.firstFrame = 2;
	clyde.lastFrame = 3;

	inky.createChar("workspace/pacman/img/inky.png", 12, 0.35);
	inky.destRec.x = 45*10 + inky.frameWidth/8+5;
	inky.destRec.y = 515;
	inky.willMove = true;
	inky.frameSpeed = 5;
	inky.firstFrame = 2;
	inky.lastFrame = 3;

	pinky.createChar("workspace/pacman/img/pinky.png", 12, 0.35);
	pinky.destRec.x = 45*11 + pinky.frameWidth/8+5;
	pinky.destRec.y = 515;
	pinky.willMove = true;
	pinky.frameSpeed = 5;
	pinky.firstFrame = 2;
	pinky.lastFrame = 3;

	pacmanTitle = LoadTexture("workspace/pacman/img/pacmanTitle.png");
}

void World::loadSounds(){

	intro = LoadSound("workspace/pacman/audio/intro.ogg");
	eating = LoadSound("workspace/pacman/audio/eating.ogg");
	death = LoadSound("workspace/pacman/audio/death.ogg");
	killGhost = LoadSound("workspace/pacman/audio/killGhost.ogg");
	invencible = LoadSound("workspace/pacman/audio/invencible.ogg");
}

void World::resetWorld(){
	for(int i = 0 ; i < 21 ; i++)
	{
		for(int j = 0 ; j < 21 ; j++)
		{
			if (cell[i][j].wall == false && cell[i][j].outOfBounds == false)
			{
				cell[i][j].dot = true;
			}
		}
	}
	cell[2][2].powerDot = true;
	cell[2][18].powerDot = true;
	cell[15][2].powerDot = true;
	cell[15][18].powerDot = true;
	blinky.setDanger(0);
	pinky.setDanger(0);
	inky.setDanger(0);
	clyde.setDanger(0);
	pacman.destRec.x = 45*11 - 23;
	pacman.destRec.y = 45*16 - 23;
	pacman.rotation = 90*3;
	pacman.direction = 1;
	pacman.change = 1;
	blinky.destRec.x = 45*10 + blinky.frameWidth/8+5;
	blinky.destRec.y = 45*6 + blinky.frameHeight/2;
	blinky.sourceRec.x = (float)1*(float)blinky.frameWidth;

	clyde.destRec.x = 45*9 + clyde.frameWidth/8+5;
	clyde.destRec.y = 515;
	clyde.sourceRec.x = (float)1*(float)clyde.frameWidth;

	inky.destRec.x = 45*10 + inky.frameWidth/8+5;
	inky.destRec.y = 515;
	inky.sourceRec.x = (float)1*(float)inky.frameWidth;

	pinky.destRec.x = 45*11 + pinky.frameWidth/8+5;
	pinky.destRec.y = 515;
	pinky.sourceRec.x = (float)1*(float)pinky.frameWidth;

	lose = false;
	powerDotActivated = false;
	powerDotTimer = 0;
	gameStage = 1;
}

void World::resetSolution(){
	for(int i = 0 ; i < 21 ; i++)
	{
		for(int j = 0 ; j < 21 ; j++)
		{
			cell[i][j].in = false;
			cell[i][j].visited = false;
		}
	}
}

bool World::checkWin(){
	for (int i = 0; i < 21; ++i)
	{
		for (int j = 0; j < 21; ++j)
		{
			if (cell[i][j].dot == true)
			{
				return false;
			}
		}
	}
	return true;
}

void World::Init(){
	PlaySound(intro);
	while(IsSoundPlaying(intro))
	{}
	gameStage = 2;
}

void World::Menu(){
	if (IsKeyPressed(KEY_SPACE))
	{
		resetWorld();
		gameStage = 1;
	}
}

void World::MainGame(){


	// ---------------------------------------------------
	// 					TIME COUNTER
	// ---------------------------------------------------

	currentFrame++;
	if (currentFrame % 30 == 0)
	{
		solution = false;
		resetSolution();
	}
	if (currentFrame >= 120)
	{
		currentFrame = 0;
		inky.change = rand() % 4 + 1;
		pinky.change = rand() % 4 + 1;
		clyde.change = rand() % 4 + 1;
	}

	if (powerDotActivated == true)
	{
		if (IsSoundPlaying(killGhost)==false)
		{
			ResumeSound(invencible);
		}
		if (IsSoundPlaying(killGhost) == false && IsSoundPlaying(invencible)==false)
		{
			PlaySound(invencible);
		}

		if (blinky.danger == false && blinky.death == false && activatedFlag == false)
		{
			blinky.setDanger(1);
		}
		if (inky.danger == false && inky.death == false && activatedFlag == false)
		{
			inky.setDanger(1);
		}
		if (pinky.danger == false && pinky.death == false && activatedFlag == false)
		{
			pinky.setDanger(1);
		}
		if (clyde.danger == false && clyde.death == false && activatedFlag == false)
		{
			clyde.setDanger(1);
		}

		if (activatedFlag == false)
		{
			activatedFlag = true;
		}
		

		powerDotTimer++;
		if (powerDotTimer >= 600)
		{
			StopSound(invencible);
			powerDotTimer = 0;
			powerDotActivated = 0;
			activatedFlag = false;
			if (blinky.death == false)
			{
				blinky.setDanger(0);
			}
			if (pinky.death == false)
			{
				pinky.setDanger(0);
			}
			if (inky.death == false)
			{
				inky.setDanger(0);
			}
			if (clyde.death == false)
			{
				clyde.setDanger(0);
			}
		}
	}

	if(IsKeyPressed(KEY_RIGHT))
	{
		pacman.change = 1;
	}
	if(IsKeyPressed(KEY_DOWN))
	{
		pacman.change = 2;
	}
	if(IsKeyPressed(KEY_LEFT))
	{
		pacman.change = 3;
	}
	if(IsKeyPressed(KEY_UP))
	{
		pacman.change = 4;
	}
	if (checkWin() == true)
	{
		gameStage = 3;
	}
	if (canChangeDirection(&pacman, pacman.change))
	{
		pacman.direction = pacman.change;
		pacman.rotation = pacman.change*90;
	}

	pacman.willMove = moveMent(pacman.direction, &pacman);
	


	// ---------------------------------------------------
	// 					GHOSTS AI
	// ---------------------------------------------------

	/******* BLINKY *******/
	if (blinky.death)
	{
		if(blinky.setBack(45*10 + blinky.frameWidth/8 + 5, 45*6 + blinky.frameHeight/2))
		{
			blinky.death = false;
			blinky.setDanger(0);
		}
	}
	else
	{
		blinky.willMove = moveMent(blinky.direction, &blinky);
	}

	Solve(blinky.destRec, pacman.destRec);

	blinky.direction = followPacman(&blinky);

	if (blinky.willMove == false)
	{
		blinky.notMoving++;
		if (blinky.notMoving >= 5)
		{
			blinky.notMoving = 0;
			blinky.movimientoAnterior = rand() % 4 + 1;
		}
	}

	/******* INKY *******/
	if (inky.death)
	{
		if(inky.setBack(45*10 + inky.frameWidth/8+5, 515))
		{
			inky.death = false;
			inky.setDanger(0);
		}
	}
	else
	{
		inky.willMove = moveMent(inky.direction, &inky);
	}
	if (inky.willMove == false)
	{
		inky.direction = rand() % 4 + 1;
	}

	if (canChangeDirection(&inky, inky.change))
	{
		inky.direction = inky.change;
		inky.framesCounter = 80;
	}

	/******* PINKY *******/
	if (pinky.death)
	{
		if(pinky.setBack(45*11 + pinky.frameWidth/8+5, 515))
		{
			pinky.death = false;
			pinky.setDanger(0);
		}
	}
	else
	{
		pinky.willMove = moveMent(pinky.direction, &pinky);
	}
	if (pinky.willMove == false)
	{
		pinky.direction = rand() % 4 + 1;
	}

	if (canChangeDirection(&pinky, pinky.change))
	{
		pinky.direction = pinky.change;
		pinky.framesCounter = 80;
	}

	/******* CLYDE *******/
	if (clyde.death)
	{
		if(clyde.setBack(45*9 + clyde.frameWidth/8+5, 515))
		{
			clyde.death = false;
			clyde.setDanger(0);
		}
	}
	else
	{
		clyde.willMove = moveMent(clyde.direction, &clyde);
	}
	if (clyde.willMove == false)
	{
		clyde.direction = rand() % 4 + 1;
	}

	if (canChangeDirection(&clyde, clyde.change))
	{
		clyde.direction = clyde.change;
		clyde.framesCounter = 80;
	}

	pacman.Update(0);
	blinky.Update(1);
	inky.Update(1);
	pinky.Update(1);
	clyde.Update(1);

	Collision();

	removeDot(&pacman);
}

void World::EndGame(){
	pacman.destRec.x = 0;
	pacman.destRec.y = 2000;
	blinky.destRec.x = 0;
	blinky.destRec.y = 2000;
	clyde.destRec.x = 0;
	clyde.destRec.y = 2000;
	inky.destRec.x = 0;
	inky.destRec.y = 2000;
	pinky.destRec.x = 0;
	pinky.destRec.y = 2000;
	currentFrame++;
	StopSound(intro);
	StopSound(intro);
	StopSound(intro);
	StopSound(intro);
	StopSound(intro);
	if (currentFrame >= 120)
	{
		if (IsKeyPressed(KEY_SPACE))
		{
			resetWorld();
		}
		if (IsKeyPressed(KEY_ENTER))
		{
			gameStage = 0;
		}
	}
}

void World::Update(){
	if (gameStage == 0)
	{
		Menu();
	}
	else if (gameStage == 3)
	{
		EndGame();
	}
	else if(gameStage == 2)
	{
		MainGame();
	}
	else if (gameStage == 1)
	{
		Init();
	}
}

void World::Render(){
	if (gameStage == 3)
	{
		if (lose)
		{
			DrawText("PERDISTE", screenWidth/2 - MeasureText("PERDISTE", 50)/2, screenHeight/2, 50, white);
		}
		else
		{
			DrawText("GANASTE", screenWidth/2 - MeasureText("GANASTE", 50)/2, screenHeight/2, 50, white);
		}
		DrawText("Presiona SPACE para reiniciar", screenWidth/2 - MeasureText("Presiona SPACE para reiniciar", 30)/2, screenHeight/2+200, 30, white);
		DrawText("Presiona ENTER para ir al menú", screenWidth/2 - MeasureText("Presiona ENTER para ir al menú", 30)/2, screenHeight/2+300, 30, white);
	}else if (gameStage == 1 || gameStage == 2){
		for(int i = 0 ; i < 21 ; i ++ )
		{
			for(int j = 0 ; j < 21 ; j++)
			{
				if(cell[i][j].wall == true)
				{
					DrawRectangle(j*cell[i][j].size, i*cell[i][j].size, cell[i][j].size, cell[i][j].size, blue);
				}
				if(cell[i][j].dot == true)
				{
					DrawCircle(j*cell[i][j].size + cell[i][j].size/2, i*cell[i][j].size + cell[i][j].size/2, cell[i][j].size/7, white);
				}
				if (cell[i][j].powerDot == true)
				{
					DrawCircle(j*cell[i][j].size + cell[i][j].size/2, i*cell[i][j].size + cell[i][j].size/2, cell[i][j].size/3, white);
				}
			}
		}
	}else if (gameStage == 0)
	{
		pacman.destRec.x = 350;
		pacman.destRec.y = 45*15 + pacman.frameWidth/6 + 1;
		pacman.sourceRec.x = (float)3*(float)pacman.frameWidth;
		pacman.rotation = 90;

		blinky.destRec.x = 450;
		blinky.destRec.y = 45*15 + blinky.frameWidth/8 + 5;
		blinky.sourceRec.x = (float)2*(float)blinky.frameWidth;

		pinky.destRec.x = 500;
		pinky.destRec.y = 45*15 + pinky.frameWidth/8 + 5;
		pinky.sourceRec.x = (float)2*(float)pinky.frameWidth;

		inky.destRec.x = 550;
		inky.destRec.y = 45*15 + inky.frameWidth/8 + 5;
		inky.sourceRec.x = (float)2*(float)inky.frameWidth;

		clyde.destRec.x = 600;
		clyde.destRec.y = 45*15 + clyde.frameWidth/8 + 5;
		clyde.sourceRec.x = (float)2*(float)clyde.frameWidth;

		DrawTexture(pacmanTitle, screenWidth/2-pacmanTitle.width/2, 100, white);
		DrawText("Press SPACE to start", screenWidth/2-MeasureText("Press Space to start", 50)/2, 500, 50, white);
	}
	pacman.Render();
	blinky.Render();
	pinky.Render();
	inky.Render();
	clyde.Render();
}

void World::removeDot(Character *name){
	int x = (name->destRec.x)/45;
	int y = (name->destRec.y)/45;

	if (cell[y][x].dot == true)
	{
		if (IsSoundPlaying(eating)==false && IsSoundPlaying(invencible) == false)
		{
			PlaySound(eating);
		}
		
		cell[y][x].dot = false;
	}
	if (cell[y][x].powerDot == true)
	{
		PlaySound(invencible);
		cell[y][x].powerDot = false;
		powerDotActivated = true;
		activatedFlag = false;
		powerDotTimer = 0;
	}
}

bool World::canMove(Character *name, int direction){

	int x = (name->destRec.x)/45;
	int y = (name->destRec.y)/45;


	switch(direction)
	{
		case 1:
			x = (name->destRec.x + 2 + (45/2))/45;
			if (x >= 21)
			{
				x = 20;
			}
			if (cell[y][x].wall == false)
			{
				return true;
			}
			break;
		case 2:
			y = (name->destRec.y + 2 + (45/2))/45;
			if (y >= 21)
			{
				y = 20;
			}
			if (cell[y][x].wall == false)
			{
				return true;
			}
			break;
		case 3:
			x = (name->destRec.x - 2 - (45/2))/45;
			if (x <= 0)
			{
				x = 0;
			}
			if (cell[y][x].wall == false)
			{
				return true;
			}
			break;
		case 4:
			y = ((name->destRec.y - 2 - (45/2))/45);
			if (y <= 0)
			{
				y = 0;
			}
			if (cell[y][x].wall == false)
			{
				return true;
			}
			break;
	}
	return false;

}

bool World::canChangeDirection(Character *name, int direction){
	int x = (name->destRec.x+23);
	int y = (name->destRec.y+23);
	int currentRow = x/45;
	int currentCol = y/45;
	if(x%45 <= 4 && y%45 <= 4 && canMove(name, direction) == true){return true;}
	return false;
}

int World::followPacman(Character *name){
	int x = (name->destRec.x);
	int y = (name->destRec.y);
	int currentRow = x/45;
	int currentCol = y/45;
	int direction = 1;

	if((x - 21)%45 <= 4 && (y - 20)%45 <= 4 && canMove(name, direction) == true && cell[currentCol][currentRow+1].visited == true && name->movimientoAnterior != 3 && name->willMove == true){
		name->movimientoAnterior = 1;
		return direction;
	}
	direction = 2;
	if((x - 21)%45 <= 4 && (y - 20)%45 <= 4 && canMove(name, direction) == true && cell[currentCol+1][currentRow].visited == true && name->movimientoAnterior != 4 && name->willMove == true){
		name->movimientoAnterior = 2;
		return direction;
	}
	direction = 3;
	if((x - 21)%45 <= 4 && (y - 20)%45 <= 4 && canMove(name, direction) == true && cell[currentCol][currentRow-1].visited == true && name->movimientoAnterior != 1 && name->willMove == true){
		name->movimientoAnterior = 3;
		return direction;
	}
	direction = 4;
	if((x - 21)%45 <= 4 && (y - 20)%45 <= 4 && canMove(name, direction) == true && cell[currentCol-1][currentRow].visited == true && name->movimientoAnterior != 2 && name->willMove == true){
		name->movimientoAnterior = 4;
		return direction;
	}
	return name->movimientoAnterior;

}

bool World::moveMent(int direction, Character *name){
	int pruebas;
	int size = 45;
	switch (direction){
		case 1:
			if (canMove(name, direction))
			{
				name->destRec.x = name->destRec.x + 1*name->velocity;
				if (name->destRec.x >= 960)
				{
					name->destRec.x = -10;
				}
				return true;
			}
			else
			{
				pruebas = name->destRec.x;
				while(pruebas%45 != 0){
					name->destRec.x = name->destRec.x + 1;
					pruebas = name->destRec.x;
				}
				name->destRec.x = name->destRec.x - 45/2;
			}
		break;
		case 2:
			if (canMove(name, direction))
			{
				name->destRec.y = name->destRec.y + 1*name->velocity;
				return true;
			}
			else
			{
				pruebas = name->destRec.y;
				while(pruebas%45 != 0){
					name->destRec.y = name->destRec.y + 1;
					pruebas = name->destRec.y;
				}
				name->destRec.y = name->destRec.y - 45/2;
			}
		break;
		case 3:
			if (canMove(name, direction))
			{
				name->destRec.x = name->destRec.x - 1*name->velocity;
				if (name->destRec.x<=-15)
				{
					name->destRec.x = 950;
				}
				return true;
			}
			else
			{
				pruebas = name->destRec.x;
				while(pruebas%45 != 0){
					name->destRec.x = name->destRec.x - 1;
					pruebas = name->destRec.x;
				}
				name->destRec.x = name->destRec.x + 45/2;
			}
		break;
		case 4:
			if (canMove(name, direction))
			{
				name->destRec.y = name->destRec.y - 1*name->velocity;
				return true;
			}
			else
			{
				pruebas = name->destRec.y;
				while(pruebas%45 != 0){
					name->destRec.y = name->destRec.y - 1;
					pruebas = name->destRec.y;
				}
				name->destRec.y = name->destRec.y + 45/2;
			}
		break;
		default:
		name->destRec.x = name->destRec.x;
		name->destRec.y = name->destRec.y;
		break;
	}		
	return false;	
}


void World::MoveSolve(Rectangle current)
{
	int col = current.y / 45;
	int row = current.x / 45;
	cell[col][row].in = true;
	cell[col][row].visited = true;
}

void World::RedoMove(Rectangle current)
{
	int col = current.y / 45;
	int row = current.x / 45;
	cell[col][row].in = false;
	cell[col][row].visited = false;
}



bool World::IsValidPosition(Rectangle p)
{
	int pCol = p.y/45;
	int pRow = p.x/45;

	if (pCol < 21 && pCol >= 0 && pRow < 21 && pRow >= 0)
	{
		return true;
	}
	return false;
}


bool World::canGhostMove(Rectangle ghost)
{
	int currentCol = ghost.y / 45;
	int currentRow = ghost.x / 45;
	if (cell[currentCol][currentRow].wall == false && cell[currentCol][currentRow].visited == false)
	{
		return true;
	}
	return false;

}

void World::Solve(Rectangle ghost, Rectangle pacman)
{
	int currentCol = ghost.y/45;
	int currentRow = ghost.x/45;
	int prevCol = ghost.y/45;
	int prevRow = ghost.x/45;
	int pacmanCol = pacman.y/45;
	int pacmanRow = pacman.x/45;

	prevCol = currentCol;
	prevRow = currentRow;
	if (currentCol != pacmanCol || currentRow != pacmanRow)
	{
		//derecha
		ghost.x += 45;
		if (IsValidPosition(ghost) == true && canGhostMove(ghost) == true && currentRow <= pacmanRow && solution == false)
		{
			currentRow = ghost.x;
			prevCol = currentCol;
			prevRow = currentRow;
			MoveSolve( ghost );
			Solve( ghost, pacman);
			if(solution == false){
				RedoMove( ghost );
			}
		}
		ghost.x -= 45;
		//abajo
		ghost.y += 45;
		if (IsValidPosition(ghost) == true && canGhostMove(ghost) == true && currentCol <= pacmanCol && solution == false)
		{
			currentCol = ghost.y;
			prevCol = currentCol;
			prevRow = currentRow;
			MoveSolve( ghost );
			Solve( ghost, pacman);
			if(solution == false){
				RedoMove( ghost );
			}
		}
		ghost.y -= 45;
		//izquierda
		ghost.x -= 45;
		if (IsValidPosition(ghost) == true && canGhostMove(ghost) == true && currentRow >= pacmanRow && solution == false)
		{
			currentRow = ghost.x;
			prevCol = currentCol;
			prevRow = currentRow;
			MoveSolve( ghost );
			Solve( ghost, pacman);
			if(solution == false){
				RedoMove( ghost );
			}
		}
		ghost.x += 45;
		//Arriba
		ghost.y -= 45;
		if (IsValidPosition(ghost) == true && canGhostMove(ghost) == true && currentCol >= pacmanCol && solution == false)
		{
			currentCol = ghost.y;
			prevCol = currentCol;
			prevRow = currentRow;
			MoveSolve( ghost );
			Solve( ghost, pacman);
			if(solution == false){
				RedoMove( ghost);
			}
		}
		ghost.y += 45;

	}
	else
	{
		solution = true;
	}
}

bool World::Collision(){
	int pacmanCol = pacman.destRec.y / 45;
	int pacmanRow = pacman.destRec.x / 45;
	int blinkyCol = blinky.destRec.y / 45;
	int blinkyRow = blinky.destRec.x / 45;
	int pinkyCol = pinky.destRec.y / 45;
	int pinkyRow = pinky.destRec.x / 45;
	int inkyCol = inky.destRec.y / 45;
	int inkyRow = inky.destRec.x / 45;
	int clydeCol = clyde.destRec.y / 45;
	int clydeRow = clyde.destRec.x / 45;

	if (pacmanCol == blinkyCol && pacmanRow == blinkyRow)
	{
		if (blinky.death == false)
		{
			if (blinky.danger == true)
			{
				PlaySound(killGhost);
				while(IsSoundPlaying(killGhost)){};
				blinky.death = true;
				blinky.setDanger(1);
			}
			else if(blinky.danger == false)
			{
				lose = true;
				currentFrame = 0;
				gameStage = 3;
				if (IsSoundPlaying(invencible))
				{
					StopSound(invencible);
				}
				PlaySound(death);
			}
			
			return true;
		}
		
	}
	if (pacmanCol == pinkyCol && pacmanRow == pinkyRow)
	{
		if (pinky.death == false)
		{
			if (pinky.danger == true)
			{
				PlaySound(killGhost);
				while(IsSoundPlaying(killGhost)){};
				pinky.death = true;
				pinky.setDanger(1);
			}
			else if(pinky.danger == false)
			{
				lose = true;
				currentFrame = 0;
				gameStage = 3;
				if (IsSoundPlaying(invencible))
				{
					StopSound(invencible);
				}
				PlaySound(death);
			}
			return true;
		}
	}
	if (pacmanCol == inkyCol && pacmanRow == inkyRow)
	{
		if (inky.death == false)
		{
			if (inky.danger == true)
			{
				PlaySound(killGhost);
				while(IsSoundPlaying(killGhost)){};
				inky.death = true;
				inky.setDanger(1);
			}
			else if(inky.danger == false)
			{
				lose = true;
				currentFrame = 0;
				gameStage = 3;
				if (IsSoundPlaying(invencible))
				{
					StopSound(invencible);
				}
				PlaySound(death);
			}
			return true;
		}
		
	}
	if (pacmanCol == clydeCol && pacmanRow == clydeRow)
	{
		if (clyde.death == false)
		{
			if (clyde.danger == true)
			{
				PlaySound(killGhost);
				while(IsSoundPlaying(killGhost)){};
				clyde.death = true;
				clyde.setDanger(1);
			}
			else if(clyde.danger == false && clyde.death == false)
			{
				lose = true;
				currentFrame = 0;
				gameStage = 3;
				if (IsSoundPlaying(invencible))
				{
					StopSound(invencible);
				}
				PlaySound(death);
			}
			return true;
		}
	}

	return false;
}

void World::Unload(){
	UnloadTexture(pacman.name);
	UnloadTexture(blinky.name);
	UnloadTexture(clyde.name);
	UnloadTexture(inky.name);
	UnloadTexture(pinky.name);
	UnloadSound(intro);
	UnloadSound(eating);
	UnloadSound(death);
	UnloadSound(killGhost);
	UnloadTexture(pacmanTitle);
}