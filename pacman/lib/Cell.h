#pragma once

class Cell{
public:
	int size;
	bool wall;
	bool pacman;
	bool dot;
	bool powerDot;
	bool outOfBounds;
	bool in;
	bool visited;
	int x;
	int y;
	Cell();
	~Cell();
};