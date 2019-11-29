#pragma once
#include <vector>

struct sPosition;
class YINSH_TIT;


enum ePotType;
class Pot;
class Player;
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

	

	bool CanMoving(Player * player);//내가 가진 링중 하나라도 한칸이상 움직일수 있는지 확인
};