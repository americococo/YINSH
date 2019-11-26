#pragma once

#include <map>
#include "../sPosition.h"
#include "../Map/MapManager.h"

class Ring;
class Marker;

class YINSH_TIT
{
private:
    /* data */
	Ring * _ring;
	Marker * _marker;

    sPosition _position;

    std::map<eDirection,YINSH_TIT *> Near_TIT;

    int setting_Near_TIT()
    {
        int x;
        int y;
        //  vector N  = ( 0,  1)
        //  vector NE = ( 1,  1)
        //  vector SE = ( 1,  0)
        //  vector S  = ( 0, -1)
        //  vector SW = (-1, -1)
        //  vector NW = (-1,  0)


        //전체맵에서 해당좌표에있는 노드가져옴
        //singleTon으로구현
        

		for (int i = 0; i < 6; i++)
		{
			Near_TIT[i] = MapManager::GetInstance().getTit(vector[i]);
		}

        //Near_TIT[eDirection::eNorth]     = MapManager::GetInstance().getTit(vector[eDirection::eNorth);
        //Near_TIT[eDirection::eNorthEast] = MapManager::GetInstance().getTit(_position._x + 1 ,_position._y + 1);
        //Near_TIT[eDirection::eSouthEast] = MapManager::GetInstance().getTit(_position._x + 1 ,_position._y + 0);
        //Near_TIT[eDirection::eSouth]     = MapManager::GetInstance().getTit(_position._x + 0 ,_position._y + (-1));
        //Near_TIT[eDirection::eSouthWest] = MapManager::GetInstance().getTit(_position._x + (-1) ,_position._y + (-1));
        //Near_TIT[eDirection::eNorthWest] = MapManager::GetInstance().getTit(_position._x + (-1) ,_position._y + 0);

        return 0;
    }


public:
    YINSH_TIT();
    YINSH_TIT(sPosition setingPosition);
    ~YINSH_TIT();

    Ring * returnRing();
    Marker * returnMarker();

    YINSH_TIT * getNearTit(int direction);

	void SettingRing(Ring * ring);
	void SettingMarker(Marker * ring);
};
