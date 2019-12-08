#pragma once

#include "../Pot.h"

class Sprite;
class Marker :public Pot
{
private:
	Sprite * _reverColorSprite;


public:
	Marker(bool color, Player * player, sPosition  postition);
	~Marker();

	void reverse();

	bool GetColor() { return _color; }//0ÀÌ black , 1ÀÌ white

};

