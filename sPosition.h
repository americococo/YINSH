#pragma once

struct sPosition
{
    /* data */
    int _x;
    int _y;
};

sPosition addPosition(sPosition a,sPosition b)
{
     int x= a._x + b._x;
     int y= a._y + b._y;
     sPosition c;
     c._x = x;
     c._y = y;
     return c;
}
void setPosition(sPosition to,sPosition from)
{
    to = from;
}
bool samePostion(sPosition a, sPosition b)
{
	if (a._x == b._x)
		if (a._y == b._y)
			return true;
	return false;
}

enum eDirection
{
    eNorth,
    eNorthEast,
    eSouthEast,
    eSouth,
    eSouthWest,
    eNorthWest,
};

static sPosition vector[6] =
{
	{  0,  1},
	{  1,  1},
	{  1,  0},
	{  0,  -1},
	{  -1,  -1},
	{  -1,  0}
};

        //  vector N  = ( 0,  1)
        //  vector NE = ( 1,  1)
        //  vector SE = ( 1,  0)
        //  vector S  = ( 0, -1)
        //  vector SW = (-1, -1)
        //  vector NW = (-1,  0)