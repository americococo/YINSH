#include "Com.h"

#include "../../System/InputSystem.h"
#include "../../Map/MapManager.h"
#include "../../sPosition.h"

#include "../../TIT/Yinsh_TIT.h"

#include "../../Pot/Ring/Ring.h"
#include "../../Pot/Marker/Marker.h"
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
	if (InputSystem::GetInstance().IsInputKey(SDLK_SPACE) == true)
	{
		int x = InputSystem::GetInstance().GetMousePositionX();
		int y = InputSystem::GetInstance().GetMousePositionY();

		//½ÇÁÂÇ¥ xy¸¦ Åä´ë·Î MapÁÂÇ¥ µµÃâ

		sPosition asdkjaksdj;
		asdkjaksdj = MapManager::GetInstance().GetTITGamePosition(x, y);

		if (MapManager::GetInstance().getTit(asdkjaksdj)->returnPot(ePotType::eRING)==nullptr)
		{
			Ring * ring = new Ring(false, this, asdkjaksdj);
			_rings.push_back(ring);

			return true;
		}
	}
	return false;
}

bool Com::SettingMarker()
{
	if (InputSystem::GetInstance().IsInputKey(SDLK_SPACE) == true)
	{
		int x = InputSystem::GetInstance().GetMousePositionX();
		int y = InputSystem::GetInstance().GetMousePositionY();

		//½ÇÁÂÇ¥ xy¸¦ Åä´ë·Î MapÁÂÇ¥ µµÃâ

		sPosition asdkjaksdj;
		asdkjaksdj = MapManager::GetInstance().GetTITGamePosition(x, y);

		if (nullptr == MapManager::GetInstance().getTit(asdkjaksdj)->returnPot(ePotType::eRING))
			return false;

		if (MapManager::GetInstance().getTit(asdkjaksdj)->returnPot(ePotType::eRING)->getOwner() == this
			&&  MapManager::GetInstance().getTit(asdkjaksdj)->returnPot(ePotType::eMarker) == nullptr)
		{
			Marker * marker= new Marker(false, this, asdkjaksdj);
			_markers.push_back(marker);

			return true;
		}
	}
	return false;
}