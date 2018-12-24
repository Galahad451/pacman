#include "raylib.h"
#include <iostream>
#include "time.h"
#include "Character.h"
#include "colores.h"
#include "World.h"
#include "Variables.h"

using namespace std;

int contadorSoluciones = 0;
int movimiento = 1;

// ---------------------------------------------------
// 			PACMAN MAIN MOVEMENT FUNCTION
// ---------------------------------------------------

int main()
{

	srand(time(NULL));
	World *world = new World();

	InitWindow(screenWidth, screenHeight, "Pacman");
	SetTargetFPS(60);

	InitAudioDevice();
    
	world->createCharacters();
	world->loadSounds();


	// ---------------------------------------------------
	// 			MAIN PROGRAM
	// ---------------------------------------------------


	while(!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(black);
		world->Render();
		EndDrawing();
		world->Update();
	}
	world->Unload();
    CloseAudioDevice();
	CloseWindow();
	return 0;
}