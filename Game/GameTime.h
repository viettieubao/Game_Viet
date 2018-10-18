#pragma once
#include "Global.h"
#include <Windows.h>
class GameTime
{
public:
	LARGE_INTEGER timeStart;
	LARGE_INTEGER timeEnd;
	LARGE_INTEGER timeFreq;
	float minFrameTime;
	float maxFrameTime;
	static GameTime* instance;
	static GameTime* GetInstance();
	float frameTime;
	bool canCreateFrame();
	
	GameTime(void);
	~GameTime(void);
};

