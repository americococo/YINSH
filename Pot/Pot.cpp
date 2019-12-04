#include "Pot.h"

#include "../Map/MapManager.h"

#include "../Player/Player.h"
Pot::Pot(bool color,Player * player ,sPosition  postition)
{
	_color = color;
	_sPostion = postition;
	_owner = player;
	//MapManager::GetInstance().SettingPot(this,,_sPostion);
}
Pot::Pot()
{

}
Pot::~Pot()
{

}
Player * Pot::getOwner()
{
	return _owner; 
}
sPosition Pot::GetPostion()
{
	return _sPostion;
}