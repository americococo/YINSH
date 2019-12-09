#include "TurnManager.h"

#include "../Player/Player.h"
#include "../Player/User/User.h"
#include "../Player/Com/Com.h"

#include "../TIT/Yinsh_TIT.h"
#include "../Pot/Ring/Ring.h"
#include "../Pot/Marker/Marker.h"


#include "../Map/MapManager.h"

TurnManager::TurnManager()
{
	_deleteMarker.clear();
	Player * p1 = new User();
	Player * p2 = new Com();

	_playerList.push_back(p1);
	_playerList.push_back(p2);
	
	_playerListitr = _playerList.begin();
	
	_playerch.push_back(p1);
	_playerch.push_back(p2);
	cirleNum = 0;
}

TurnManager::~TurnManager()
{
}

bool TurnManager::Update()
{
	bool endChk=false;


	Player * p = (*_playerListitr);
	

	//링 5개 설치 안되있음(초기)
	if(p->RingCount() != 5)
	{	
		if (true == p->settingRing())
		{
			_playerListitr++;
			if (_playerListitr == _playerList.end())
				_playerListitr = _playerList.begin();
		}
		return endChk;
	}


	else if(MapManager::GetInstance().CanMoving(p))
	{
		if (true == p->SettingMarker())
		{
			_playerListitr++;
			if (_playerListitr == _playerList.end())
				_playerListitr = _playerList.begin();
		}
	}
	
	


	if (p->MarkerCount() > 5)
	{
		for (int i = 0; i <= p->MarkerCount(); i++)
		{
			for (int y = 0; y < 6; y++)
			{
				if (CHEAKY(y, ((Marker*)p->GetPot(ePotType::eMarker)[i])) == true)
				{
					CheckDelete();
				}
			}
		}
	}
	
	{
		Player * ppp = _playerList.front();
		Player * p2 = _playerList.back();
		
		if (ppp->GetScore() || p2->GetScore())
		{
			endChk = true;
		}
	}




	return endChk;
}

void TurnManager::CheckDelete()
{
	if (_deleteMarker.size() == 0)
		return;

	while(_deleteMarker.empty())
	{
		Marker * deleteMarker = _deleteMarker.back();
		MapManager::GetInstance().ResetMarker(deleteMarker);
		(*_playerListitr)->ResetMarker(deleteMarker);
		_deleteMarker.pop_back();
	}

	return;

}

bool TurnManager::CHEAKY(int direction,Marker * marker)
{
	int i = 0;

	do
	{
		YINSH_TIT * tit = MapManager::GetInstance().getTit(marker->GetPostion())->getNearTit(((eDirection)direction));
		if (tit == nullptr)
		{
			_deleteMarker.clear();
			return false;
		}


		Marker * marko = (Marker*)(tit->returnPot(ePotType::eMarker));
		if (marko != nullptr)
			if (marko->getOwner() != marker->getOwner())
			{
				_deleteMarker.clear();
				return false;
			}

		if (marko == nullptr)
		{
			_deleteMarker.clear();
			return false;
		}

		_deleteMarker.push_back(marko);
		i++;

	} while (i<4);

	_deleteMarker.push_back(marker);

	marker->getOwner()->GainScore();


	return true;
}

std::vector<Player *> TurnManager::GetPlayer()
{
	return _playerch;

}