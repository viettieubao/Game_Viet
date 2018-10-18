#pragma once
#include "Global.h"
#include "WindowGame.h"
#include <d3d9.h>
#include <d3dx9.h>
#include <Windows.h>
class Graphic
{
private:
	LPDIRECT3DDEVICE9 d3ddv; //load hình anh
	LPDIRECT3DSURFACE9 frameBuffer; //hinh ve hien tai
	LPDIRECT3DSURFACE9 backBuffter; // hinh trong bo nho tam
	LPD3DXSPRITE sprite;
	HWND hWnd;
	bool isInitDirectX();
	bool isInitSprite();
	bool isSetFrameBuffer();
	bool isSetBackBuffer();
	void init();
	void error();
	static Graphic *instance;
public:

	static Graphic* getInstance();
	void  Release();
	LPDIRECT3DDEVICE9 GetDevice();
	LPDIRECT3DSURFACE9 GetBackBuffer();
	LPD3DXSPRITE GetSprite();
	void BeginGraphics();
	void EndGraphics();
	void PresentBackBuffer();

	Graphic(HWND hWnd);
	~Graphic(void);
};

