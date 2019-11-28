#include "Player.h"
#include "../Pot/Pot.h"

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
