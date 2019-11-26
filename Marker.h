#pragma once

enum eDirection;
struct sPosition;

class Ring
{
private:
	bool _color;
	sPosition _sPostion;
public:
	Ring(bool color, sPosition postition);
	~Ring();


	void move(eDirection direction, int walkPoint);

};

