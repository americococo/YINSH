#include "Ring.h"
#include "../../Map/MapManager.h"
#include "../../TIT/Yinsh_TIT.h"
#include "../Marker/Marker.h"


#include "../../Draw/Sprite/Sprite.h"
Ring::Ring(bool color, Player * player, sPosition postition)
{
	_color = color;
	_sPostion = postition;
	_owner = player;
	_pic = new Sprite("Ring.png");

	


	MapManager::GetInstance().SettingPot(this,ePotType::eRING, _sPostion);
	_realPositionX = MapManager::GetInstance().getTit(_sPostion)->GetrealPositionX();
	_realPositionY = MapManager::GetInstance().getTit(_sPostion)->GetrealPositionY();
	_pic->setPosition(_realPositionX, _realPositionY);
	//_pic->setscale(1.1, 1.1);
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