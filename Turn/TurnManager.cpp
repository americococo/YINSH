#include "TurnManager.h"
#include "../Player/Player.h"
#include "../Map/MapManager.h"
TurnManager::TurnManager()
{
	Player * p1 = new Player();
	Player * p2 = new Player();

	_playerList.apend(p1);
	_playerList.apend(p2);
	_playeritr = _playerList.GetIterator();

	cirleNum = 0;
	_playeritr.start();
}

TurnManager::~TurnManager()
{
}

void TurnManager::Update()
{
	if (_playeritr.valid() == false)
		_playeritr.start();
	
	Player * p = _playeritr.item();
	
	//if(ring 설치여부 확인)
	//{	
	//p1->settingRing();
	//return;
	//}


	//if(ring 이동가능 확인)	MapManager::GetInstance().CanMoving(p);
	//p1->marker setting 및 ring 이동
	//Ring , Chip 제거할것 체크
	//std::vector<pot*> markers = p->GetPot(ePotType::eMarker);
	//std::vector<pot*> rings = p->GetPot(ePotType::eChip);
	//std::vector<Player*> scoreGetPs = CheckDelete(markers,rings);<- 리턴값 삭제된 칩&링의 주인(들(두 플레이어 모두 득점일 가능성))
	//for(int i =0;i<scoreGetPs.size();i++)
	//{
	//	scoreGetPs[i]->hittingScore();//1점획득
	//}
	
	_playeritr.Forth();
	
	


	
}