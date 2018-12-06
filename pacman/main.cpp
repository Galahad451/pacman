#include "raylib.h"
#include "colores.h"
#include <iostream>

#define screenWidth 945
#define screenHeight 945

// ---------------------------------------------------
// 						COLORS
// ---------------------------------------------------
Color white = {255,255,255,255};


// ---------------------------------------------------
// 			PACMAN MAIN MOVEMENT FUNCTION
// ---------------------------------------------------

class Celda{
public:
	int size;
	bool wall;
	bool pacman;
	bool dot;
	bool outOfBounds;
	int x;
	int y;
	Celda();
	~Celda();
};

Celda::Celda(){
	size = 45;
	wall = false;
	pacman = false;
}

Celda::~Celda(){}

class Map{
public:
	Celda cell[21][21];
	Map();
	~Map();
	void resetMap();
};

Map::Map(){
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

	for(int i = 0 ; i < 21 ; i++)
	{
		for(int j = 0 ; j < 21 ; j++)
		{
			cell[i][j].x = 45 + 45*j;
			cell[i][j].y = 45 + 45*i;
			cell[i][j].wall = arr[i][j];
			cell[i][j].outOfBounds = outOfBoundsArray[i][j];
			if (cell[i][j].wall == false && cell[i][j].outOfBounds == false)
			{
				cell[i][j].dot = true;
			}
		}
	}
}	
Map::~Map(){}

void Map::resetMap(){
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
}

void removeDot(Map *map, Rectangle *position){
	int x = (position->x)/45;
	int y = (position->y)/45;

	if (map->cell[y][x].dot == true)
	{
		map->cell[y][x].dot = false;
	}
}

bool canMove(Map *map, Rectangle *position, int direction){

	int x = (position->x)/45;
	int y = (position->y)/45;


	switch(direction)
	{
		case 1:
			x = (position->x + 2 + (45/2))/45;
			if (x > 21)
			{
				x = 20;
			}
			if (map->cell[y][x].wall == false)
			{
				return true;
			}
			break;
		case 2:
			y = (position->y + 2 + (45/2))/45;
			if (y > 21)
			{
				y = 20;
			}
			if (map->cell[y][x].wall == false)
			{
				return true;
			}
			break;
		case 3:
			x = (position->x - 2 - (45/2))/45;
			if (x <= 0)
			{
				x = 0;
			}
			if (map->cell[y][x].wall == false)
			{
				return true;
			}
			break;
		case 4:
			y = ((position->y - 2 - (45/2))/45);
			if (y <= 0)
			{
				y = 0;
			}
			if (map->cell[y][x].wall == false)
			{
				return true;
			}
			break;
	}
	return false;

}

bool canChangeDirection(Map *map, Rectangle *position, int direction){
	int x = (position->x+23);
	int y = (position->y+23);
	int xx = x/45;
	int yy = y/45;
	if(x%45 <= 4 && y%45 <= 4 && canMove(map, position, direction) == true){return true;}
	return false;
}

bool moveMent(int number, Rectangle *position, int vel, Map *map){
	int pruebas;
	int size = 45;
	switch (number){
		case 1:
			if (canMove(map, position, number))
			{
				position->x = position->x + 1*vel;
				return true;
			}
			else
			{
				pruebas = position->x;
				while(pruebas%45 != 0){
					position->x = position->x + 1;
					pruebas = position->x;
				}
				position->x = position->x - 45/2;
			}
		break;
		case 2:
			if (canMove(map, position, number))
			{
				position->y = position->y + 1*vel;
				return true;
			}
			else
			{
				pruebas = position->y;
				while(pruebas%45 != 0){
					position->y = position->y + 1;
					pruebas = position->y;
				}
				position->y = position->y - 45/2;
			}
		break;
		case 3:
			if (canMove(map, position, number))
			{
				position->x = position->x - 1*vel;
				return true;
			}
			else
			{
				pruebas = position->x;
				while(pruebas%45 != 0){
					position->x = position->x - 1;
					pruebas = position->x;
				}
				position->x = position->x + 45/2;
			}
		break;
		case 4:
			if (canMove(map, position, number))
			{
				position->y = position->y - 1*vel;
				return true;
			}
			else
			{
				pruebas = position->y;
				while(pruebas%45 != 0){
					position->y = position->y - 1;
					pruebas = position->y;
				}
				position->y = position->y + 45/2;
			}
		break;
		default:
		position->x = position->x;
		position->y = position->y;
		break;
	}		
	return false;	
}

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
	bool willMove;
	Rectangle sourceRec;
	Rectangle destRec;
	Vector2 origin;

	void createChar(const char* source, int frames, float size);
	void Render();
	void Update(int firstFrame, int lastFrame);
};

Character::Character(){
	rotation = 0;
	framesCounter = 0;
	currentFrame = 0;
	frameSpeed = 12;
	willMove = false;
}

Character::~Character(){
	UnloadTexture(name);
}

void Character::createChar(const char* source, int frames, float size){
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

void Character::Render(){
	DrawTexturePro(name, sourceRec, destRec, origin, rotation, white);
}

void Character::Update(int firstFrame, int lastFrame){
	framesCounter++;

	if(framesCounter >= 60/frameSpeed && willMove == true)
	{
		framesCounter = 0;
		currentFrame++;
		if(currentFrame > lastFrame){currentFrame = firstFrame;}
		sourceRec.x = (float)currentFrame*(float)frameWidth;
	}
}

int main()
{
	Map *map = new Map();
	Colores *color = new Colores();

	InitWindow(screenWidth, screenHeight, "Pacman");
	SetTargetFPS(60);

	// ---------------------------------------------------
	// 			PACMAN CREATION
	// ---------------------------------------------------



	Character blinky;
	blinky.createChar("workspace/pacman/img/blinky.png", 8, 0.35);
	blinky.destRec.x = 45*8 + blinky.frameWidth/8+5;
	blinky.destRec.y = 515;
	blinky.willMove = true;
	blinky.frameSpeed = 5;

	Character clyde;
	clyde.createChar("workspace/pacman/img/clyde.png", 8, 0.35);
	clyde.destRec.x = 45*9 + clyde.frameWidth/8+5;
	clyde.destRec.y = 515;
	clyde.willMove = true;
	clyde.frameSpeed = 5;

	Character inky;
	inky.createChar("workspace/pacman/img/inky.png", 8, 0.35);
	inky.destRec.x = 45*10 + inky.frameWidth/8+5;
	inky.destRec.y = 515;
	inky.willMove = true;
	inky.frameSpeed = 5;

	Character pinky;
	pinky.createChar("workspace/pacman/img/pinky.png", 8, 0.35);
	pinky.destRec.x = 45*11 + pinky.frameWidth/8+5;
	pinky.destRec.y = 515;
	pinky.willMove = true;
	pinky.frameSpeed = 5;

	Character pacman;
	pacman.createChar("workspace/pacman/img/pacman.png", 6, 0.3);
	//15, 10
	pacman.destRec.x = 45*10 + pacman.frameWidth/6 + 1;
	pacman.destRec.y = 45*15 + pacman.frameWidth/6 + 1;

	Rectangle *destRecPacman = &pacman.destRec;
	Rectangle *destRecClyde = &clyde.destRec;

	int pacmanMove = 0;
	int clydeMove = 1;
	int change = 0;
	int velocity = 6;

	// ---------------------------------------------------
	// 			MAIN PROGRAM
	// ---------------------------------------------------


	while(!WindowShouldClose())
	{
		pacman.Update(0, 5);
		blinky.Update(2, 3);
		clyde.Update(2, 3);
		inky.Update(2, 3);
		pinky.Update(2, 3);
		// ---------------------------------------------------
		// 			PACMAN MOVEMENT
		// ---------------------------------------------------
		if (canChangeDirection(map, destRecPacman, change))
		{
			pacmanMove = change;
			pacman.rotation = change*90;
		}

		pacman.willMove = moveMent(pacmanMove, destRecPacman, velocity, map);
		clyde.willMove = moveMent(clydeMove, destRecClyde, velocity, map);
		if (clyde.willMove == false)
		{
			std::cout << "Ya no se puede mover" << std::endl;
			clydeMove++;
			if (clydeMove >= 5)
			{
				clydeMove = 1;
			}
		}
		removeDot(map, destRecPacman);

		if(IsKeyPressed(KEY_RIGHT))
		{
			change = 1;
		}
		if(IsKeyPressed(KEY_DOWN))
		{
			change = 2;
		}
		if(IsKeyPressed(KEY_LEFT))
		{
			change = 3;
		}
		if(IsKeyPressed(KEY_UP))
		{
			change = 4;
		}
		if(IsKeyPressed(KEY_SPACE))
		{
			pacman.destRec.x = 45*11 - 23;
			pacman.destRec.y = 45*16 - 23;
			pacman.rotation = 90*3;
			map->resetMap();
			pacmanMove = 0;
			change = 0;
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

		// ---------------------------------------------------
		// 			MAIN DRAWING
		// ---------------------------------------------------

		BeginDrawing();
		ClearBackground(color->GetColor(0,0,0,255));
		// ---------------------------------------------------
		// 			MAZE DRAWING
		// ---------------------------------------------------
		for(int i = 0 ; i < 21 ; i ++ )
		{
			for(int j = 0 ; j < 21 ; j++)
			{
				if(map->cell[i][j].wall == true)
				{
					DrawRectangle(j*map->cell[i][j].size, i*map->cell[i][j].size, map->cell[i][j].size, map->cell[i][j].size, color->GetColor(52, 93, 169, 255));
				}
				if(map->cell[i][j].dot == true)
				{
					DrawCircle(j*map->cell[i][j].size + map->cell[i][j].size/2, i*map->cell[i][j].size + map->cell[i][j].size/2, map->cell[i][j].size/7, color->GetColor(255,255,255,255));
				}
				// DrawText(FormatText("%i", map->cell[i][j].x), j*map->cell[i][j].size + 45/2 - MeasureText(FormatText("%i", map->cell[i][j].x), 20)/2, i*map->cell[i][j].size  + 45/2 - MeasureText(FormatText("%i", map->cell[i][j].x), 20)/2, 20, color->GetColor(255,255,255,255));
			}
		}
		// ---------------------------------------------------
		// 			PACMAN DRAWING
		// ---------------------------------------------------
		pacman.Render();
		blinky.Render();
		clyde.Render();
		inky.Render();
		pinky.Render();
		EndDrawing();
	}
	UnloadTexture(pacman.name);
	UnloadTexture(blinky.name);
	UnloadTexture(clyde.name);
	UnloadTexture(inky.name);
	UnloadTexture(pinky.name);
	CloseWindow();
	return 0;
}