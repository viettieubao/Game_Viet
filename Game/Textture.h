#pragma once
#include "Graphic.h"
class Textture
{
private:
	LPDIRECT3DTEXTURE9 m_image;
public:
	int Width, Height;


	Textture( const char*, D3DCOLOR);
	void Init(const char*, D3DCOLOR);
	void RenderTexture(int, int, RECT*);
	Textture();
	~Textture();
};

