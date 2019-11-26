#include "Yinsh_TIT.h"
#include "../Pot/Marker/Marker.h"
#include "../Pot/Ring/Ring.h"
YINSH_TIT::YINSH_TIT()
{
	_marker = nullptr;
	_ring = nullptr;
}
YINSH_TIT::YINSH_TIT(sPosition setingPosition)
{
    YINSH_TIT();
    _position = setingPosition;
}
YINSH_TIT::~YINSH_TIT()
{
}

Marker * YINSH_TIT::returnMarker()
{
	return _marker;
}
Ring * YINSH_TIT::returnRing()
{ return _ring;}

YINSH_TIT  * YINSH_TIT::getNearTit(int direction)
{
    if(direction ==0)
        return this;

    return Near_TIT[(eDirection(direction))];
}
void YINSH_TIT::SettingRing(Ring * ring)
{
	_ring = ring;
}
void  YINSH_TIT::SettingMarker(Marker * marker)
{
	_marker = marker;
}