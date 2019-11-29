#include "TurnManager.h"
#include "../Player/Player.h"
#include "../Map/MapManager.h"

#include "../TIT/Yinsh_TIT.h"
#include "../Pot/Ring/Ring.h"
#include "../Pot/Marker/Marker.h"
#include "../sPosition.h"

TurnManager::TurnManager()
{
	_deleteMarker.clear();
	Player * p1 = new Player();
	Player * p2 = new Player();

	_playerList.push_back(p1);
	_playerList.push_back(p2);
	
	_playerListitr = _playerList.begin();

	cirleNum = 0;
}

TurnManager::~TurnManager()
{
}

void TurnManager::Update()
{
	if (_playerListitr != _playerList.end())
		_playerListitr = _playerList.begin();

	_playerListitr++;
	
	Player * p = (*_playerListitr);
	
	//if(ring 설치여부 확인)
	//{	
	//p1->settingRing();
	//return;
	//}


	//if(ring 이동가능 확인)	MapManager::GetInstance().CanMoving(p);
	//p1->marker setting 및 ring 이동
	//_playeritr.Forth();
	//Player * _2p = _playeritr.item();
	//_playeritr.Back();
	//Ring , Chip 제거할것 체크
	//CHEAKY(int direction, Marker * marker);
	
	//for(int i = 0; i < = p1->GetPot(ePotType::eMarker).size();i++)
	//{
	//	for(int y = 0; y < 6; y++)
	//	{
	//		CHEAKY(y, p1->GetPot(ePotType::eMarker)[i]);
	//	}
	//}
	//점수 추가
	_playerListitr++;

}

void TurnManager::CheckDelete()
{
	if (_deleteMarker.size == 0)
		return;
	//while(_deleteMarker.empty())
	//{
	//	Marker * deleteMarker = _deleteMarker.push_back();
	//	MapManager::GetInstance().GetResetMarker(deleteMarker);
	//	(*_playerListitr).GetResetMarker(deleteMarker);
	//}
	//CheckDelete();
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


	_deleteMarker.push_back(marker);

	CheckDelete();

	return true;
}