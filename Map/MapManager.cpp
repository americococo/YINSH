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
				postionL._y = 4;
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
            _mapData[-5][x] = tit;
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
	return _mapData[postion._x][postion._y];
}
void MapManager::SettingPot(Pot * pot, ePotType type,sPosition  postion)
{
	_mapData[postion._x][postion._y]->SettingPot(pot,type);
}

void MapManager::MoveRing(sPosition form, sPosition to)
{

	_mapData[to._x][to._y] = _mapData[form._x][form._y];

	_mapData[form._x][form._y]->SettingPot(nullptr,ePotType::eRING);
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
			if (nullptr == _mapData[chpoint2._x][chpoint2._y]->returnPot(ePotType::eRING))
				return true;
		}
		
	}
	
	return false;
}
void MapManager::ResetMarker(Pot * pot)
{
	sPosition  ssss = pot->GetPostion();
	_mapData[ssss._x][ssss._y]->ResetMarker();
}