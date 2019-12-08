#include "Marker.h"

#include "../../Map/MapManager.h"
#include "../../Turn/TurnManager.h"
#include "../../TIT/Yinsh_TIT.h"

#include "../../Draw/Sprite/Sprite.h"

Marker::Marker(bool color, Player * player, sPosition  postition)
{
	_color = color;
	_sPostion = postition;
	_owner = player;
	_pic = new Sprite("markerChipT");
	_reverColorSprite = new Sprite("markerChipF");
	_realPositionX = MapManager::GetInstance().getTit(_sPostion)->GetrealPositionX();
	_realPositionY = MapManager::GetInstance().getTit(_sPostion)->GetrealPositionY();
	MapManager::GetInstance().SettingPot(this, ePotType::eMarker,_sPostion);
}

Marker::~Marker()
{
}

void Marker::reverse()
{
	_color != _color;

	{
		Sprite * asdddddd;
		asdddddd = _reverColorSprite;
		_reverColorSprite = _pic;
		_pic = asdddddd;
	}
	std::vector<Player*> playerVecotr = TurnManager::GetInstance().GetPlayer();
	for (int i = 0; i < playerVecotr.size(); i++)
	{
		if (playerVecotr[i] != _owner)
		{
			_owner = playerVecotr[i];
			return;
		}
	}
	
}
