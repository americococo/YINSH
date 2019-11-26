#include "Marker.h"
#include "../../sPosition.h"
#include "../../Map/MapManager.h"
#include "../../TIT/Yinsh_TIT.h"

Marker::Marker(bool color, sPosition postition)
{
	_color = color;
	_sPostion = postition;

	MapManager::GetInstance().SettingMarker(this, _sPostion);
}

Marker::~Marker()
{
}

void Marker::reverse()
{
	_color != _color;
}
