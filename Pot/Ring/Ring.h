#pragma once

enum eDirection;

#include "../Pot.h"
class Ring:public Pot
{

public:
	Ring(bool color, Player * player, sPosition  postition);
    ~Ring();

    void move(eDirection direction , int walkPoint);

	bool GetColor() { return _color; }//0ÀÌ black , 1ÀÌ white

};
