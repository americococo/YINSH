#include "Ring.h"
#include "../../Map/MapManager.h"
#include "../../TIT/Yinsh_TIT.h"
#include "../Marker/Marker.h"

#include "../../sPosition.h"

Ring::Ring(bool color,sPosition postition)
{
	Pot(color, postition);
	
	MapManager::GetInstance().SettingPot(this,ePotType::eRING, _sPostion);
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
		Marker * marker = ((Marker*)MapManager::GetInstance().getTit(_sPostion)->returnPot(ePotType::eMarker));
		marker->reverse();
    }
    
	MapManager::GetInstance().MoveRing(original,_sPostion);

}