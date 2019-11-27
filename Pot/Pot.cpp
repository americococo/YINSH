#include "Pot.h"

#include "../Map/MapManager.h"

Pot::Pot(bool color, sPosition postition)
{
	_color = color;
	_sPostion = postition;

	//MapManager::GetInstance().SettingPot(this,,_sPostion);
}
Pot::Pot()
{

}
Pot::~Pot()
{

}
