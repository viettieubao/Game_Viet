#include "Sprite.h"

Sprite::Sprite(const char* imgFilePath, const char* animationInfoFilePath) {
	init(imgFilePath, animationInfoFilePath);
}


void Sprite::init(const char* imgFilePath, const char* animationInfoFilePath) {
	int r, g, b;
	fstream fs(animationInfoFilePath);
	fs >> r >> g >> b >> nAnimation;

	animations = new Animation[nAnimation];
	for (int i = 0; i < nAnimation; i++) {
		animations[i].init(fs);
	}
}
void Sprite::draw(int x, int y, int curAnimation, int curFrame) {
	Animation* animation = &animations[curAnimation];
	image->RenderTexture(x, y, &animation->frames[curFrame].toRECT());
}
Sprite::Sprite()
{
}


Sprite::~Sprite()
{
}
