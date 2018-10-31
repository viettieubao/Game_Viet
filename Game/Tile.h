#pragma once
#include <fstream>
#include "Textture.h"
#include "Global.h"
using namespace std;
class Tile
{
public:
	float viewportWith, viewportHeight;
	float xMap, yMap;

	Textture tileSheetImg;
	int rowCount, columnCount;
	int ** matrixTile;
	static Tile* curMap;

	void convertToViewPos(int xInMap, int yInMap, int& xViewport, int & xViewPort);
	void render();
	void renderTile(int rowIndex, int columnIndex);
	void renderTiles(int rowBegin, int rowEnd, int colBegin, int colEnd);
	void init(const char* tilemap, const char* tileSheetPath);
	

	
	Tile();
	~Tile();
};

