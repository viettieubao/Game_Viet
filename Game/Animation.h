#pragma once
#include "RectF.h"
#include "GameTime.h"
#include <fstream>
using namespace std;
class Animation
{
public:
	RectF * frames;
	int nFrame;
	void  init(fstream & );
	void next(int& );
	Animation();
	~Animation();
};

