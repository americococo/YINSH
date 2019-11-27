#pragma once
#include <vector>

struct sPosition;
class YINSH_TIT;


enum ePotType;
class Pot;
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
	YINSH_TIT * getTit(sPosition postion);

	void SettingPot(Pot * pot,ePotType type, sPosition postion);
	void MoveRing(sPosition form,sPosition to);
};