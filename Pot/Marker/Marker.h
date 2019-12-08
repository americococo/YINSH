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

	bool GetColor() { return _color; }//0�� black , 1�� white

};

