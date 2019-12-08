#pragma once

#include <map>
#include "../sPosition.h"

class Sprite;
enum ePotType;
class Pot;
class YINSH_TIT
{
private:
    /* data */
	Pot * _ring;
	Pot * _marker;

    sPosition _sPostion;

    std::map<eDirection,YINSH_TIT *> Near_TIT;

	void setting_Near_TIT();


public:
    YINSH_TIT();
    YINSH_TIT(sPosition setingPosition);
    ~YINSH_TIT();

    Pot * returnPot(ePotType type);

    YINSH_TIT * getNearTit(int direction);

	void SettingPot(Pot * pot,ePotType type);

	void ResetMarker();

private:
	Sprite * _pic;
	int _realPositionX;
	int _realPositionY;

public:
	void Render();

	int GetrealPositionX() { return _realPositionX; }
	int GetrealPositionY() { return _realPositionY; }


	sPosition GetGamePosition() { return _sPostion; }
};
