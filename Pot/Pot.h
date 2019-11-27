#pragma once

struct sPosition;
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
	sPosition _sPostion;

public:
	Pot(bool color, sPosition postition);
	Pot();
	~Pot();

};

