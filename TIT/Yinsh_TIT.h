#pragma once

#include <map>
#include "../sPosition.h"
#include "../Map/MapManager.h"

enum ePotType;

class Pot;
class YINSH_TIT
{
private:
    /* data */
	Pot * _ring;
	Pot * _marker;

    sPosition _position;

    std::map<eDirection,YINSH_TIT *> Near_TIT;

	void setting_Near_TIT();


public:
    YINSH_TIT();
    YINSH_TIT(sPosition setingPosition);
    ~YINSH_TIT();

    Pot * returnPot(ePotType type);

    YINSH_TIT * getNearTit(int direction);


	//void SettingRing(Ring * ring);
	//void SettingMarker(Marker * ring);
	void SettingPot(Pot * pot,ePotType type);


};
