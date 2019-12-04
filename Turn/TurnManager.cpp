#include "TurnManager.h"
#include "../Player/Player.h"

#include "../TIT/Yinsh_TIT.h"
#include "../Pot/Ring/Ring.h"
#include "../Pot/Marker/Marker.h"


#include "../Map/MapManager.h"

TurnManager::TurnManager()
{
	_deleteMarker.clear();
	Player * p1 = new Player();
	Player * p2 = new Player();

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

	if (_playerListitr == _playerList.end())
		_playerListitr = _playerList.begin();

	
	Player * p = (*_playerListitr);
	

	//링 5개 설치 안되있음(초기)
	if(p->RingCount() != 5)
	{	
		p->settingRing();
		return false;
	}


	if (MapManager::GetInstance().CanMoving(p))
	{
		p->SettingMarker();

		_playerListitr++;
		Player * _2p = (*_playerListitr);
		_playerListitr--;
	}
	
	
	for(int i = 0; i <= p->GetPot(ePotType::eMarker).size(); i++)
	{
		for(int y = 0; y < 6; y++)
		{
			if (CHEAKY(y, ((Marker*)p->GetPot(ePotType::eMarker)[i])) == true)
			{
				CheckDelete();
			}
		}
	}
	
	{
		_playerListitr++;
		Player * p2 = (*_playerListitr);
		if (p->GetScore() || p2->GetScore())
		{
			endChk = true;
		}
		_playerListitr--;
	}

	_playerListitr++;



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
		Marker * marko = (Marker*)(tit->returnPot(ePotType::eMarker));
		if (marko != nullptr)
			if (marko->getOwner() != marker->getOwner())
				return false;

		if (marko == nullptr)
			return false;
		
		_deleteMarker.push_back(marko);
		i++;

	} while (i<5);

	marker->getOwner()->GainScore();

	_deleteMarker.push_back(marker);

	return true;
}

std::vector<Player *> TurnManager::GetPlayer()
{
	return _playerch;

}