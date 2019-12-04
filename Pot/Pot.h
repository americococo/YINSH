#pragma once

struct sPosition;
class Player;
#include "../sPosition.h"
enum ePotType
{
	eMarker=100,
	eRING
};

class Pot
{

protected:

	bool _color;
	sPosition  _sPostion;
	Player * _owner;

public:
	Pot(bool color, Player * player,sPosition  postition);
	Pot();
	~Pot();

	Player * getOwner();
	sPosition  GetPostion();
};

