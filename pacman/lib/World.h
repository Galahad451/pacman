#pragma once

#include "raylib.h"
#include "Cell.h"
#include "Character.h"

class World{
public:
	Cell cell[21][21];
	World();
	~World();
	int gameStage;
	bool solution;
	bool activatedFlag;
	bool powerDotActivated;
	bool lose;
	int powerDotTimer;
	int currentFrame;
	int score;
	int lives;
	Character pacman;
	Character blinky;
	Character clyde;
	Character inky;
	Character pinky;

	Texture2D pacmanTitle;

	Sound intro;
	Sound eating;
	Sound death;
	Sound killGhost;
	Sound invencible;

	void resetWorld();
	bool checkWin();
	void removeDot(Character *name);
	bool canMove(Character *name, int direction);
	bool canChangeDirection(Character *name, int direction);
	bool moveMent(int number, Character *name);
	int followPacman(Character *name);
	void resetSolution();
	void createCharacters();
	void loadSounds();

	void Solve(Rectangle ghost, Rectangle pacman);
	bool canGhostMove(Rectangle ghost);
	bool IsValidPosition(Rectangle p);
	void RedoMove(Rectangle current);
	void MoveSolve(Rectangle current);
	bool Collision();


	void Menu();
	void MainGame();
	void EndGame();
	void Init();

	void Update();
	void Render();
	void Unload();
};