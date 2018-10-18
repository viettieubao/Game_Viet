#pragma once
#include "Animation.h"
#include "Textture.h"
class Sprite
{

public:
	Animation * animations;
	Textture* image;
	int nAnimation;
	Sprite(const char*, const char*);
	void init(const char*, const char*);
	void initAnimation(const char*);
	void draw(int, int, int, int);
	Sprite();
	~Sprite();
};

