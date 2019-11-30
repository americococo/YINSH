#include "Marker.h"
#include "../../sPosition.h"
#include "../../Map/MapManager.h"
#include "../../Turn/TurnManager.h"
#include "../../TIT/Yinsh_TIT.h"

Marker::Marker(bool color, Player * player, sPosition postition)
{
	Pot(color, player,postition);

	MapManager::GetInstance().SettingPot(this, ePotType::eMarker,_sPostion);
}

Marker::~Marker()
{
}

void Marker::reverse()
{
	_color != _color;
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
