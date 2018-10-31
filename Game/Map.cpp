#include "Map.h"


void Map::init(const char* tileMatixPath, const char* tileSheetPath) {
	Tile::init(tileMatixPath, tileSheetPath);
}


void Map::draw() {
	Tile::render();
}

void Map::update() {

}

Map::Map()
{
	xMap = X_MAP;
	yMap = Y_MAP;
	viewportWith = VIEWPORT_WIDTH;
	viewportHeight = VIEWPORT_HEIGHT;
}


Map::~Map()
{
}
