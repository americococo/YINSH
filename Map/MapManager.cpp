#include "MapManager.h"
#include "../TIT/Yinsh_TIT.h"
#include "../sPosition.h"

#include "../Pot/Pot.h"
#include "../Pot/Ring/Ring.h"

#include "../Player/Player.h"

#include <vector>
MapManager::MapManager()
{
		
        int x;
        int y;
        for(x=1;x<5;x++)
        {
            sPosition postionL;
            postionL._x =x;
            postionL._y = 5;
            YINSH_TIT * tit= new YINSH_TIT(postionL);
            _mapData[5][x] = tit;
        }

		for (int y = 4; y >= 1; y--)
		{
			int zonazzaging = -1 * (y - 4);
			for (int x = -1 - zonazzaging; x <= 5; x++)
			{
				sPosition postionL;
				postionL._x = x;
				postionL._y = y;
				YINSH_TIT * tit = new YINSH_TIT(postionL);
				_mapData[y][x] = tit;
			}
		}

        for (x = -4 ; x <= 4; x++)
        {
            sPosition postionL;
            postionL._x =x;
            postionL._y = 0;
            YINSH_TIT * tit= new YINSH_TIT(postionL);
            _mapData[0][x] = tit;
        }

        for(y=-1; y >= -4; y--)
        {
			for (x = -5; x <= 4 + (y+1); x++)
            {
               sPosition postionL;
               postionL._x =x;
               postionL._y = y;
               YINSH_TIT * tit= new YINSH_TIT(postionL);
              _mapData[y][x] = tit;
            }
            
            
        }

        for(x=-1;x > -5;x--)
        {
            sPosition postionL;
            postionL._x =x;
            postionL._y = -5;
            YINSH_TIT * tit= new YINSH_TIT(postionL);
            _mapData[y][x] = tit;
        }

}
MapManager::~MapManager()
{

}
void MapManager::Render()
{
	std::map<int, std::map<int, YINSH_TIT*>>::iterator mapAllPleace;
	for (mapAllPleace = _mapData.begin(); mapAllPleace != _mapData.end(); mapAllPleace++)
	{
		std::map<int, YINSH_TIT*>::iterator mapPleace;
		
		for (mapPleace = (*mapAllPleace).second.begin(); mapPleace != (*mapAllPleace).second.end(); mapPleace++)
		{
			(*mapPleace).second->Render();
		}
	}
}
YINSH_TIT * MapManager::getTit(sPosition postion)
{
	return _mapData[postion._y][postion._x];
}
void MapManager::SettingPot(Pot * pot, ePotType type,sPosition  postion)
{
	_mapData[postion._y][postion._x]->SettingPot(pot,type);
}

void MapManager::MoveRing(sPosition form, sPosition to)
{

	_mapData[to._y][to._x] = _mapData[form._y][form._x];

	_mapData[form._y][form._x]->SettingPot(nullptr,ePotType::eRING);
}

bool MapManager::CanMoving(Player * player)
{
	std::vector<Pot*> pots = player->GetPot(ePotType::eRING);
	std::vector<Pot*>::iterator itr= pots.begin();
	for (pots.begin();itr!= pots.end(); itr++)
	{
		sPosition chPoint;
		chPoint = (*itr)->GetPostion();
		for (int i = 0; i < 6; i++)
		{
			sPosition chpoint2;
			chpoint2 = addPosition(chPoint, vector[i]);
			if (nullptr == _mapData[chpoint2._y][chpoint2._x]->returnPot(ePotType::eRING))
				return true;
		}
		
	}
	
	return false;
}
void MapManager::ResetMarker(Pot * pot)
{
	sPosition  ssss = pot->GetPostion();
	_mapData[ssss._y][ssss._x]->ResetMarker();
}

sPosition MapManager::GetTITGamePosition(int RealPositionX, int RealPositionY)
{
	sPosition a_cocococo;

	std::map<int, std::map<int, YINSH_TIT*>>::iterator mapAllPleace;
	for (mapAllPleace = _mapData.begin(); mapAllPleace != _mapData.end(); mapAllPleace++)
	{
		std::map<int, YINSH_TIT*>::iterator mapPleace;

		for (mapPleace = (*mapAllPleace).second.begin(); mapPleace != (*mapAllPleace).second.end(); mapPleace++)
		{
			int realX = (*mapPleace).second->GetrealPositionX();
			int realY = (*mapPleace).second->GetrealPositionY();

			int minX = realX - 32 * 1.1 /2;
			int maxX = minX + 32 * 1.1;

			int minY = realY - 32 * 1.1 / 2;
			int maxY = realY + 32 * 1.1;

			if (minX<RealPositionX && maxX > RealPositionX &&
				minY < RealPositionY && maxY > RealPositionY)
			{
				a_cocococo = (*mapPleace).second->GetGamePosition();
				return a_cocococo;
			}
			
		}
	}

}