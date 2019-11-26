#pragma once
#include <vector>

struct sPosition;
class YINSH_TIT;

class Ring;

class MapManager
{
private:
    std::vector<std::vector<YINSH_TIT*>> _mapData;

    MapManager();
public:

	~MapManager();
    static MapManager & GetInstance()
    {
        static MapManager * instance = new  MapManager();
        return * instance;
    }
    YINSH_TIT * getTit(sPosition postion) 
	{
		return _mapData[postion._x][postion._y];
	}

	//void SettingComp(Comp * comp, sPosition postion);
	

	void SettingRing(Ring * ring, sPosition postion);
	void SettingMarker(Marker * marker, sPosition postion);

	void MoveRing(sPosition form,sPosition to);
};