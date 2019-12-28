#pragma once
#include <map>

struct sPosition;
class YINSH_TIT;


enum ePotType;
class Pot;
class Player;
class MapManager
{
private:
	std::map<int, std::map<int, YINSH_TIT*>> _mapData;
	
    MapManager();
public:

	~MapManager();
    static MapManager & GetInstance()
    {
        static MapManager * instance = new  MapManager();
        return * instance;
    }

	void Render();
	YINSH_TIT * getTit(sPosition postion);

	void SettingPot(Pot * pot,ePotType type, sPosition postion);
	void MoveRing(sPosition form,sPosition to);

	

	bool CanMoving(Player * player);//내가 가진 링중 하나라도 한칸이상 움직일수 있는지 확인

	void ResetMarker(Pot * pot);

	bool GetTITGamePosition(int RealPositionX, int RealPositionY, sPosition * result);
};