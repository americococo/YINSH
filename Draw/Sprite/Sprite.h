#pragma once
#include <SDL_image.h>
//struct SDL_Texture;
//struct SDL_Rect;

class Sprite
{
private:
	SDL_Rect _srcRect;
	SDL_Rect _destRect;
	SDL_Texture * _sprite;

public:
	Sprite();
	Sprite(const char * fileName);
	void setscale(float W, float h);
	void setPosition(int x, int y);
	void Render();

	int getRenderWidth();
	int getRenderHeight();
};