#include "Ring.h"
#include "../../sPosition.h"
#include "../../Map/MapManager.h"
#include "../../TIT/Yinsh_TIT.h"

Ring::Ring(bool color,sPosition postition)
{
    _color = color;
    _sPostion = postition;
	
	MapManager::GetInstance().SettingRing(this, _sPostion);
}

Ring::~Ring() 
{
}

void Ring::move(eDirection direction, int walkPoint)
{
    sPosition another;
    another._x = vector[direction]._x * walkPoint;
    another._y = vector[direction]._y * walkPoint;

    sPosition From;
    From = addPosition(_sPostion,another);

	sPosition original;
	original = _sPostion;

    while (samePostion(From,_sPostion))
    {
		_sPostion._x += vector[direction]._x;
		_sPostion._y += vector[direction]._y;
		//MapManager::GetInstance().getTit(_sPostion)->returnMarker().reverse();
    }
    

	MapManager::GetInstance().MoveRing(original,_sPostion);

}