#include "Player.h"
#include "../Pot/Pot.h"
#include "../Pot/Ring/Ring.h"
Player::Player()
{
	_score = 0;
	_rings.clear();
	_markers.clear();
}

Player::~Player()
{
}
std::vector<Pot *> Player::GetPot(ePotType type)
{
	std::vector<Pot *> pots;

	switch (type)
	{
	case eMarker:
		pots = _markers;
		break;
	case eRING:
		pots = _rings;
		break;
	}
	return pots;	
}
int Player::RingCount()
{
	return _rings.size();
}
void Player::settingRing()
{
	//�� ����
	
	//������ �ϱ����� ��ǥ�� ����
	//��ǥ���� ���� �� ����
	//Ring * ring = new Ring(true, this, settingPosition); // 1.���� 1p -> 1 2p-> 0, 2. owner  3.settingposition
	//_rings.push_back(ring);
}
void Player::SettingMarker()
{
	//Ĩ ������
	//�� �̵� ����

	
}