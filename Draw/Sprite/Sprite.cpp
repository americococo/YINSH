#include "Sprite.h"
#include "../../System/System.h"

#include <stdio.h>
#include <string>


Sprite::Sprite()
{

}
Sprite::Sprite(const char * fileName)
{
	_texture = nullptr;
	
	char filePaht[256];
	
	sprintf(filePaht, "./Draw/Image/%s", fileName);

	_texture = IMG_LoadTexture(System::GetInstance().GetRenderer(), filePaht);


	//_Sprite = RecourceManger::GetInstance()->FindSprite(filePaht);

	SDL_QueryTexture(_texture, NULL, NULL, &_srcRect.w, &_srcRect.h);

	{
		_srcRect.x = 0;
		_srcRect.y = 0;

		_destRect.w = _srcRect.w;
		_destRect.h = _srcRect.h;
	}
}
void Sprite::setPosition(int x, int y)
{

	_x = x;
	_y = y;

	_destRect.x = x - getRenderWidth() / 2;
	_destRect.y = y - getRenderHeight() / 2;
}

void Sprite::setscale(float w, float h)
{
	_destRect.w = _srcRect.w*w;
	_destRect.h = _srcRect.h*h;
}

void Sprite::Render()
{
	SDL_RenderCopy(System::GetInstance().GetRenderer(), _texture, &_srcRect, &_destRect);
}
int Sprite::getRenderHeight()
{
	return _destRect.h;
}
int Sprite::getRenderWidth()
{
	return _destRect.w;
}