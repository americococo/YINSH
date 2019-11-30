#include "Yinsh_TIT.h"
#include "../Pot/Pot.h"
#include "../Pot/Marker/Marker.h"

YINSH_TIT::YINSH_TIT()
{
	_marker = nullptr;
	_ring = nullptr;
}
YINSH_TIT::YINSH_TIT(sPosition setingPosition)
{
    YINSH_TIT();
    _position = setingPosition;
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
		position._x = _position._x + vector[i]._x;
		position._y = _position._y + vector[i]._y;
		Near_TIT[((eDirection)i)] = MapManager::GetInstance().getTit(position);
	}
	
	

	//Near_TIT[eDirection::eNorth] = MapManager::GetInstance().getTit(_position._x);
	//Near_TIT[eDirection::eNorthEast] = MapManager::GetInstance().getTit(_position._x + 1, _position._y + 1);
	//Near_TIT[eDirection::eSouthEast] = MapManager::GetInstance().getTit(_position._x + 1, _position._y + 0);
	//Near_TIT[eDirection::eSouth] = MapManager::GetInstance().getTit(_position._x + 0, _position._y + (-1));
	//Near_TIT[eDirection::eSouthWest] = MapManager::GetInstance().getTit(_position._x + (-1), _position._y + (-1));
	//Near_TIT[eDirection::eNorthWest] = MapManager::GetInstance().getTit(_position._x + (-1), _position._y + 0);

	return;
}
Pot * YINSH_TIT::returnPot(ePotType type)
{
	switch (type)
	{
	case eMarker:
		 return _marker;
	case eRING:
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
		_ring = pot; break;
	case eRING:
		_marker = pot; break;
	}
}

void YINSH_TIT::ResetMarker()
{
	_marker = nullptr;
}