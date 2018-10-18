#include "Animation.h"

void Animation::init(fstream & fs) {
	int id;
	fs >> id >> nFrame;
	frames = new RectF(nFrame);
	for (int i = 0; i < nFrame; i++) {
		fs >> frames[i].x;
		fs >> frames[i].y;
		fs >> frames[i].width;
		fs >> frames[i].height;
	}
}

Animation::Animation()
{
}


Animation::~Animation()
{
	delete[] frames;
}
