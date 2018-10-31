#pragma once
#include "Tile.h"
class Map : public Tile
{
public:

	void init(const char* tileMatrixPath, const char* tileSheetPath);
	void update();
	void draw();

	Map();
	~Map();
};

