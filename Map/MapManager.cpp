#include "MapManager.h"
#include "../TIT/Yinsh_TIT.h"
#include "../sPosition.h"

#include "../Pot/Ring/Ring.h"
#include "../Pot/Marker/Marker.h"
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
            _mapData[x][y] = tit;
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
            _mapData[x][y] = tit;
        }

}
MapManager::~MapManager()
{

}
void MapManager::SettingRing(Ring * ring, sPosition postion)
{
	_mapData[postion._x][postion._y]->SettingRing(ring);
}
void MapManager::SettingMarker(Marker * marker, sPosition postion)
{
	_mapData[postion._x][postion._y]->SettingMarker(marker);
}

void MapManager::MoveRing(sPosition form, sPosition to)
{
	_mapData[to._x][to._y] = _mapData[form._x][form._y];

	_mapData[form._x][form._y] = nullptr;
}