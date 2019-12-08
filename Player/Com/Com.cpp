#include "Com.h"
Com::Com()
{
	Player::Player();
	_playerType = ePlayerType::eCom;
}

Com::~Com()
{
	Player::~Player();
}

bool Com::settingRing()
{
	//if (InputSystem::GetInstance().isMouseDown() == true)
	//{
	//	int x = InputSystem::GetInstance().GetMousePositionX();
	//	int y = InputSystem::GetInstance().GetMousePositionY();

	//	//실좌표 xy를 토대로 Map좌표 도출
	//	sPosition askdjaksdj;
	//	askdjaksdj._x = 0;
	//	askdjaksdj._y = 0;
	//	Ring * ring = new Ring(true, this, askdjaksdj);
	//	_rings.push_back(ring);

	//	return true;
	//}

	return false;
}

bool Com::SettingMarker()
{
	return false;
}