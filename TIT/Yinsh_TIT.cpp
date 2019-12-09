#include "Yinsh_TIT.h"
#include "../Pot/Pot.h"
#include "../Pot/Marker/Marker.h"
#include "../Map/MapManager.h"

#include "../Draw/Sprite/Sprite.h"

YINSH_TIT::YINSH_TIT()
{

}
YINSH_TIT::YINSH_TIT(sPosition setingPosition)
{
	_marker = nullptr;
	_ring = nullptr;
	_sPostion = setingPosition;



	_pic = new Sprite("TITb.png");
	_pic->setscale(1.1, 1.1);

	int x;
	int y;

	x = -11;
	y = -33;

	
	{
		if (_sPostion._x == 0 && _sPostion._y == 0)
		{
			y = _sPostion._y + 300;
			x = 400;
		}
		if (_sPostion._x == 0 && _sPostion._y > 0)
		{
			y = 300 - (_sPostion._y * 32 * 1.1);
			x = 400;
		}
		if (_sPostion._x == 0 && _sPostion._y < 0)
		{
			y = 300 + (_sPostion._y*-1 * 32 * 1.1);
			x = 400;
		}
	}

	{
		if (_sPostion._x > 0)
		{
			if (_sPostion._y == 0)
			{
				y = _sPostion._y + 300 + _sPostion._x * 32 / 2 * 1.1;
				x = 400 + _sPostion._x * 32 * 1.1;
			}
			if (_sPostion._y > 0)
			{
				y = 300 - (_sPostion._y * 32 * 1.1) + _sPostion._x * 32 / 2 * 1.1;
				x = 400 + _sPostion._x * 32 * 1.1;
			}
			if (_sPostion._y < 0)
			{
				y = 300 + (_sPostion._y*-1 * 32 * 1.1) + _sPostion._x * 32 / 2 * 1.1;
				x = 400 + _sPostion._x * 32 * 1.1;
			}
		}
		else if (_sPostion._x < 0)
		{
			if (_sPostion._y == 0)
			{
				y = _sPostion._y + 300 + _sPostion._x * 32 / 2 * 1.1;
				x = 400 + _sPostion._x * 32 * 1.1;
			}
			if (_sPostion._y > 0)
			{
				y = 300 - (_sPostion._y * 32 * 1.1) + _sPostion._x * 32 / 2 * 1.1;
				x = 400 + _sPostion._x * 32 * 1.1;
			}
			if (_sPostion._y < 0)
			{
				y = 300 + (_sPostion._y*-1 * 32 * 1.1) + _sPostion._x * 32 / 2 * 1.1;
				x = 400 + _sPostion._x * 32 * 1.1;
			}
		}
	}

	_realPositionX = x;
	_realPositionY = y;

	_pic->setPosition(_realPositionX, _realPositionY);
}
YINSH_TIT::~YINSH_TIT()
{
}
void YINSH_TIT::setting_Near_TIT()
{
	
	//  vector N  = ( 0,  1)
	//  vector NE = ( 1,  1)
	//  vector SE = ( 1,  0)
	//  vector S  = ( 0, -1)
	//  vector SW = (-1, -1)
	//  vector NW = (-1,  0)


	//전체맵에서 해당좌표에있는 노드가져옴
	//singleTon으로구현


	for (int i = 0; i < 6; i++)
	{
		sPosition position;
		position._x = _sPostion._x + vector[i]._x;
		position._y = _sPostion._y + vector[i]._y;
		Near_TIT[((eDirection)i)] = MapManager::GetInstance().getTit(position);
	}
	
	
	//예외처리
	//해줘해줘잉~~~

	return;
}
Pot * YINSH_TIT::returnPot(ePotType type)
{


	switch (type)
	{
	case eMarker:
		if (_marker == nullptr)
			return nullptr;
		 return _marker;
	case eRING:
		if (_ring == nullptr)
			return nullptr;
		return _ring;
	}
	return nullptr;
}

YINSH_TIT  * YINSH_TIT::getNearTit(int direction)
{
    if(direction ==0)
        return this;

    return Near_TIT[(eDirection(direction))];
}

void YINSH_TIT::SettingPot(Pot * pot, ePotType type)
{
	switch (type)
	{
	case eMarker:
		_marker = pot; break;
	case eRING:
		_ring = pot; break;
	}
}

void YINSH_TIT::ResetMarker()
{
	_marker = nullptr;
}
void YINSH_TIT::Render()
{
	_pic->Render();

	if(_ring != nullptr)
		_ring->render();
	if(_marker != nullptr)
		_marker->render();
}