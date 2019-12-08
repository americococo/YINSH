#include "User.h"
#include "../../System/InputSystem.h"
#include "../../sPosition.h"

#include "../../Pot/Marker/Marker.h"
#include "../../Pot/Ring/Ring.h"
#include "../../TIT/Yinsh_TIT.h"

#include "../../Map/MapManager.h"


User::User()
{
	Player::Player();
	_playerType = ePlayerType::eUser;
}
User::~User()
{
	Player::~Player();
}

bool User::settingRing()
{
	if (InputSystem::GetInstance().isMouseDown() == true)
	{
		int x = InputSystem::GetInstance().GetMousePositionX();
		int y = InputSystem::GetInstance().GetMousePositionY();

		//½ÇÁÂÇ¥ xy¸¦ Åä´ë·Î MapÁÂÇ¥ µµÃâ
		
		sPosition asdkjaksdj;
		asdkjaksdj = MapManager::GetInstance().GetTITGamePosition(x, y);

		if (MapManager::GetInstance().getTit(asdkjaksdj)->returnPot(ePotType::eRING) == nullptr)
		{
			Ring * ring = new Ring(true, this,asdkjaksdj );
			_rings.push_back(ring);

			return true;
		}
	}
	return false;
}
bool User::SettingMarker()
{
	if (InputSystem::GetInstance().isMouseDown() == true)
	{
		int x = InputSystem::GetInstance().GetMousePositionX();
		int y = InputSystem::GetInstance().GetMousePositionY();

		//½ÇÁÂÇ¥ xy¸¦ Åä´ë·Î MapÁÂÇ¥ µµÃâ

		sPosition asdkjaksdj;
		asdkjaksdj = MapManager::GetInstance().GetTITGamePosition(x, y);

		if (MapManager::GetInstance().getTit(asdkjaksdj)->returnPot(ePotType::eRING)->getOwner() == this 
			&&  MapManager::GetInstance().getTit(asdkjaksdj)->returnPot(ePotType::eMarker) == nullptr)
		{
			Marker * marker = new Marker(true, this, asdkjaksdj);
			_markers.push_back(marker);

			return true;
		}
	}
	return false;
}