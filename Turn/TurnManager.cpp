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
	
	//if(ring ��ġ���� Ȯ��)
	//{	
	//p1->settingRing();
	//return;
	//}


	//if(ring �̵����� Ȯ��)	MapManager::GetInstance().CanMoving(p);
	//p1->marker setting �� ring �̵�
	//Ring , Chip �����Ұ� üũ
	//std::vector<pot*> markers = p->GetPot(ePotType::eMarker);
	//std::vector<pot*> rings = p->GetPot(ePotType::eChip);
	//std::vector<Player*> scoreGetPs = CheckDelete(markers,rings);<- ���ϰ� ������ Ĩ&���� ����(��(�� �÷��̾� ��� ������ ���ɼ�))
	//for(int i =0;i<scoreGetPs.size();i++)
	//{
	//	scoreGetPs[i]->hittingScore();//1��ȹ��
	//}
	
	_playeritr.Forth();
	
	


	
}