#pragma once

#include "../Pot.h"

class Marker :public Pot
{

public:
	Marker(bool color, sPosition postition);
	~Marker();

	void reverse();

	bool GetColor() { return _color; }//0ÀÌ black , 1ÀÌ white

};

