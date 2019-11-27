#include "MapManager.h"
#include "../TIT/Yinsh_TIT.h"
#include "../sPosition.h"

#include "../Pot/Pot.h"

#include "../sPosition.h"
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
            _mapData[x][5] = tit;
        }

        for(y=4; y > 0; y--)
        {
            for (x = -1 - (y-4); x <= 5; x++)
            {
               sPosition postionL;
               postionL._x =x;
               postionL._y = y;
               YINSH_TIT * tit= new YINSH_TIT(postionL);
              _mapData[x][y] = tit;
            }            
        }
        for (x = -4 ; x <= 4; x++)
        {
            sPosition postionL;
            postionL._x =x;
            postionL._y = 0;
            YINSH_TIT * tit= new YINSH_TIT(postionL);
            _mapData[x][y] = tit;
        }
        for(y=4; y > 0; y--)
        {
            for (x = -5; x <= 4 - (y-4); x++)
            {
               sPosition postionL;
               postionL._x =x;
               postionL._y = y;
               YINSH_TIT * tit= new YINSH_TIT(postionL);
              _mapData[x][y] = tit;
            }
            
            
        }

        for(x=-1;x > -5;x--)
        {
            sPosition postionL;
            postionL._x =x;
            postionL._y = -5;
            YINSH_TIT * tit= new YINSH_TIT(postionL);
            _mapData[x][-5] = tit;
        }

}
MapManager::~MapManager()
{

}
YINSH_TIT * MapManager::getTit(sPosition postion)
{
	return _mapData[postion._x][postion._y];
}
void MapManager::SettingPot(Pot * pot, ePotType type,sPosition postion)
{
	_mapData[postion._x][postion._y]->SettingPot(pot,type);
}

void MapManager::MoveRing(sPosition form, sPosition to)
{
	_mapData[to._x][to._y] = _mapData[form._x][form._y];

	_mapData[form._x][form._y]->SettingPot(nullptr,ePotType::eRING);
}