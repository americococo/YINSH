#include "Player.h"
#include "../Pot/Pot.h"
#include "../Pot/Ring/Ring.h"

#include <SDL.h>

#include "../System/InputSystem.h"
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
int Player::MarkerCount()
{
	return _markers.size();
}
bool Player::settingRing()
{
	//�� ����
	
	//������ �ϱ����� ��ǥ�� ����
	//��ǥ���� ���� �� ����
	//Ring * ring = new Ring(true, this, settingPosition); // 1.���� 1p -> 1 2p-> 0, 2. owner  3.settingposition
	//_rings.push_back(ring);

		if (InputSystem::GetInstance().IsInputKey(SDLK_SPACE)==true)
		{
			int x = InputSystem::GetInstance().GetMousePositionX();
  			int y = InputSystem::GetInstance().GetMousePositionY();

			//����ǥ xy�� ���� Map��ǥ ����
			sPosition askdjaksdj;
			askdjaksdj._x = 0;
			askdjaksdj._y = 0;
			Ring * ring = new Ring(true, this, askdjaksdj);
			_rings.push_back(ring);

			return true;
		}
	return false;
}
bool Player::SettingMarker()
{
	//Ĩ ������
	//�� �̵� ����
	
	return false;
}
bool Player::GetScore()
{
	return _score == 3 ? true :  false;
}

void Player::ResetMarker(Pot * marker)
{
	for (int i = 0; i < _markers.size(); i++)
	{
		if (_markers[i] == marker)
		{
			_markers[i] == nullptr;
		}

	}
}
void Player::GainScore()
{
	_score++;
}