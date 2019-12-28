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

		//실좌표 xy를 토대로 Map좌표 도출
		
		sPosition asdkjaksdj;
		bool possible_position;
		possible_position = MapManager::GetInstance().GetTITGamePosition(x, y, &asdkjaksdj);

		if (possible_position == true &&  MapManager::GetInstance().getTit(asdkjaksdj)->returnPot(ePotType::eRING) == nullptr)
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

		//실좌표 xy를 토대로 Map좌표 도출

		sPosition asdkjaksdj;
		bool possible_position;
		possible_position = MapManager::GetInstance().GetTITGamePosition(x, y, &asdkjaksdj);

		

		if (possible_position == true && nullptr == MapManager::GetInstance().getTit(asdkjaksdj)->returnPot(ePotType::eRING))
			return false;

		if ( MapManager::GetInstance().getTit(asdkjaksdj)->returnPot(ePotType::eRING)->getOwner() == this 
			&&  MapManager::GetInstance().getTit(asdkjaksdj)->returnPot(ePotType::eMarker) == nullptr)
		{
			
			
			eDirection ringMoveDirection;
			if (InputSystem::GetInstance().IsInputKey(SDLK_w))
			{
				ringMoveDirection = eDirection::eNorth;
			}
			else if (InputSystem::GetInstance().IsInputKey(SDLK_e))
			{
				ringMoveDirection = eDirection::eNorthEast;
			}
			else if (InputSystem::GetInstance().IsInputKey(SDLK_q))
			{
				ringMoveDirection = eDirection::eNorthWest;
			}
			else if (InputSystem::GetInstance().IsInputKey(SDLK_s))
			{
				ringMoveDirection = eDirection::eSouth;
			}
			else if (InputSystem::GetInstance().IsInputKey(SDLK_a))
			{
				ringMoveDirection = eDirection::eSouthWest;
			}
			else
			{
				ringMoveDirection = eDirection::eSouthEast;
			}


			int walkpoint = 0;

			if (InputSystem::GetInstance().IsInputKey(SDLK_0))
			{
				walkpoint = SDLK_0 - 48;
			}
			if (InputSystem::GetInstance().IsInputKey(SDLK_1))
			{
				walkpoint = SDLK_1 - 48;
			}
			if (InputSystem::GetInstance().IsInputKey(SDLK_2))
			{
				walkpoint = SDLK_2 - 48;
			}
			if (InputSystem::GetInstance().IsInputKey(SDLK_3))
			{
				walkpoint = SDLK_3 - 48;
			}
			if (InputSystem::GetInstance().IsInputKey(SDLK_4))
			{
				walkpoint = SDLK_4 - 48;
			}
			if (InputSystem::GetInstance().IsInputKey(SDLK_5))
			{
				walkpoint = SDLK_5 - 48;
			}
			if (InputSystem::GetInstance().IsInputKey(SDLK_6))
			{
				walkpoint = SDLK_6 -48;
			}
			if (InputSystem::GetInstance().IsInputKey(SDLK_7))
			{
				walkpoint = SDLK_7 - 48;
			}
			if (InputSystem::GetInstance().IsInputKey(SDLK_8))
			{
				walkpoint = SDLK_8 - 48;
			}
			if (InputSystem::GetInstance().IsInputKey(SDLK_9))
			{
				walkpoint = SDLK_9 - 48;
			}


			sPosition aaaaaaajjjjax = asdkjaksdj;

			for (int i = 0; i < walkpoint; i++)
			{
				aaaaaaajjjjax._x += vector[ringMoveDirection]._x;
				aaaaaaajjjjax._y += vector[ringMoveDirection]._y;

				if (MapManager::GetInstance().getTit(aaaaaaajjjjax)->returnPot(ePotType::eRING) != nullptr)
				{
					return false;
				}
			}
			Marker * marker = new Marker(true, this, asdkjaksdj);
			_markers.push_back(marker);
			((Ring*)MapManager::GetInstance().getTit(asdkjaksdj)->returnPot(ePotType::eRING))->move(ringMoveDirection, walkpoint);
			

			return true;
		}
	}
	return false;
}