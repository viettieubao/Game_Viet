#include "GameTime.h"

GameTime* GameTime::instance = 0;
GameTime* GameTime::GetInstance() {
	if (instance == 0) {
		instance = new GameTime();
	}
	return instance;
}

GameTime::GameTime(void)
{
	QueryPerformanceFrequency(&timeFreq);
	QueryPerformanceCounter(&timeStart);
}


GameTime::~GameTime(void)
{
}


bool GameTime::canCreateFrame() {
	QueryPerformanceCounter(&timeEnd);
	frameTime = (float)(timeEnd.QuadPart - timeStart.QuadPart) / (float)(timeFreq.QuadPart);
	if (frameTime < minFrameTime)
		return false;
	if (frameTime > maxFrameTime)
		frameTime = maxFrameTime;
	timeStart = timeEnd;
	return true;
}