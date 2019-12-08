#include "Pot.h"

#include "../Map/MapManager.h"

#include "../Player/Player.h"
#include "../TIT/Yinsh_TIT.h"

#include "../Draw/Sprite/Sprite.h"
Pot::Pot(bool color,Player * player ,sPosition  postition)
{
	_color = color;
	_sPostion = postition;
	_owner = player;
	_realPositionX = MapManager::GetInstance().getTit(_sPostion)->GetrealPositionX();
	_realPositionY = MapManager::GetInstance().getTit(_sPostion)->GetrealPositionY();
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

void Pot::render()
{
	_pic->Render();
}