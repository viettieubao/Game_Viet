#include "Tile.h"

void Tile::convertToViewPos(int xInMap, int yInMap, int& xViewport, int & xViewPort) {
	D3DXVECTOR3 posInMap;
	D3DXVECTOR4 posViewPort;
	D3DXMATRIX mt;

	D3DXMatrixIdentity(&mt);
	mt._41 = (int)xMap;
	mt._42 = (int)yMap;

	posInMap.x = xInMap;
	posInMap.y = yInMap;
	posInMap.z = 0;

	D3DXVec3Transform(&posViewPort, &posInMap, &mt);
	xViewPort = posViewPort.x;
	xViewport = posViewPort.y;
}
Tile* Tile::curMap = 0;

void Tile::renderTile(int rowIndex, int columnIndex) {
	int xTileInViewport, yTileInViewport;
	int xTileInMap = columnIndex * 16;
	int yTileInMap = rowIndex * 16;
	int id = matrixTile[rowIndex][columnIndex];
	convertToViewPos(xTileInMap, yTileInMap, xTileInViewport, yTileInViewport);

	RECT r;
	SetRect(&r, id * 16, 0, id * 16 + 16, 16);
	tileSheetImg.RenderTexture(xTileInViewport, yTileInViewport, &r);
}

void Tile::renderTiles(int rowBegin, int rowEnd, int colBegin, int colEnd) {
	if (rowBegin < 0 || colBegin < 0 || rowEnd >= rowCount || colEnd >= columnCount)
		return;
	for (int rowindex = rowBegin; rowindex <= rowEnd; rowindex++) {
		for (int colIndex = colBegin; colIndex <= colEnd; colIndex++) {
			renderTile(rowindex, colIndex);
		}
	}
}

void Tile::render() {
	int rowBegin, rowEnd, colBegin, colEnd;
	colBegin = (-xMap) / 16;
	colEnd = ((-xMap) + viewportWith) / 16;
	rowBegin=(-yMap) / 16;
	rowEnd = ((-yMap) + viewportHeight) / 16;
	renderTiles(rowBegin, rowEnd, colBegin, colEnd);

}

void Tile::init(const char* tileMatrixPath, const char* tileSheetPath) {
	fstream fs(tileMatrixPath);
	fs >> rowCount >> columnCount;

	matrixTile = new int*[rowCount];
	for (int rowIndex = 0; rowIndex < rowCount; rowIndex++) {
		matrixTile[rowIndex] = new int[columnCount];
		for (int colIndex = 0; colIndex < columnCount; colIndex++) {
			fs >> matrixTile[rowIndex][colIndex];
		}
	}
	fs.close();
	tileSheetImg.Init(tileSheetPath, D3DCOLOR_XRGB(1, 1, 1));
}

Tile::Tile()
{
	curMap = this;
}


Tile::~Tile()
{
	for (int rowIndex = 0; rowIndex < rowCount; rowIndex++) {
		delete[]matrixTile[rowIndex];

	}
	delete[] matrixTile;
}