#include "Marker.h"
#include "../../sPosition.h"
#include "../../Map/MapManager.h"
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
}
